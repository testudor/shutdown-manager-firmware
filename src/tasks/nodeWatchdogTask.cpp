#include "nodeWatchdogTask.hpp"

#define ALARM_NUM 0
#define ALARM_IRQ TIMER_IRQ_0

static void nodeTimeout(void)
{
  hw_clear_bits(&timer_hw->intr, 1u << ALARM_NUM);

  ControlMessage data = ControlMessage::NODE_TIMEOUT;

  xQueueSendToBackFromISR(xControlMessageQueue, (void *)&data, 0);
}

inline void nodeChange()
{
  xTaskNotifyFromISR(Handle_nodeWatchdogTask, 0, eSetBits, pdFALSE);
}

void nodeWatchdogTask(void *pvParameters)
{
  for (pin_size_t pinHeartbeat : PINS_HEARTBEAT)
  {
    attachInterrupt(digitalPinToInterrupt(pinHeartbeat), nodeChange, CHANGE);
  }

  bool wasDown = false;

  PinStatus nodeStates[2] = {LOW, LOW};
  const PinStatus ALL_DOWN[2] = {LOW, LOW};

  hw_set_bits(&timer_hw->inte, 1u << ALARM_NUM);
  irq_set_exclusive_handler(ALARM_IRQ, nodeTimeout);
  irq_set_enabled(ALARM_IRQ, false);

  while (true)
  {
    // Continue every 500 ms or when notified by ISR
    ulTaskNotifyTake(pdTRUE, (CONFIG_NODE_TIMEOUT_MS / 2) / portTICK_PERIOD_MS);

    if (currentSystemState == SystemState::OFF)
    {
      yield();
      continue;
    }

    uint8_t pinIdx = 0;
    for (pin_size_t pinHeartbeat : PINS_HEARTBEAT)
    {
      nodeStates[pinIdx] = digitalRead(pinHeartbeat);
      pinIdx++;
    }

    if (memcmp(nodeStates, ALL_DOWN, sizeof(nodeStates)) == 0)
    {
      if (wasDown == false)
      {
        hw_clear_bits(&timer_hw->intr, 1u << ALARM_NUM);

        uint64_t target = timer_hw->timerawl + CONFIG_NODE_TIMEOUT_MS * 1000;
        timer_hw->alarm[ALARM_NUM] = (uint32_t)target;
        irq_set_enabled(ALARM_IRQ, true);

        Serial.println("All down. Start timer.");

        wasDown = true;
      }
    }
    else
    {
      if (wasDown == true)
      {
        irq_set_enabled(ALARM_IRQ, false);

        ControlMessage data = ControlMessage::NODE_ONLINE;
        xQueueSendToBack(xControlMessageQueue, (void *)&data, 0);

        Serial.println("At least one up. Stop timer.");

        wasDown = false;
      }
    }

    yield();
  }
}