#include "controlTask.hpp"

void controlTask(void *pvParameters)
{
  for (pin_size_t pinShutdown : PINS_SHUTDOWN)
  {
    pinMode(pinShutdown, OUTPUT);
  }

  BistableRelay mainRelay(PIN_RELAY_DIR, PIN_RELAY_TRIG, false);
  mainRelay.begin();

  mainRelay.setState(false);
  delay(CONFIG_RELAY_PULSE_MS);
  mainRelay.stopPulse();

  xInputEventQueue = xQueueCreate(10, sizeof(InputEvent));
  InputEvent inputEvent;

  xControlMessageQueue = xQueueCreate(10, sizeof(ControlMessage));
  ControlMessage controlMessage;

  while (true)
  {
    while (xQueueReceive(xInputEventQueue, &inputEvent, 0) == pdPASS)
    {
      if (inputEvent.eventType == 0)
      {
        // Short press
        if (currentSystemState == SystemState::OFF)
        {
          mainRelay.setState(true);
          delay(CONFIG_RELAY_PULSE_MS);
          mainRelay.stopPulse();

          currentSystemState = SystemState::WAIT_FOR_BOOT;
          Serial.println("Turned on main power. Waiting for nodes to come online.");
        }
      }
      if (inputEvent.eventType == 1)
      {
        // Long press
        if (currentSystemState == SystemState::ON)
        {
          currentSystemState = SystemState::WAIT_FOR_SHUTDOWN;
          Serial.println("Shutdown has been triggered. Waiting for nodes to go offline.");
        }
      }
      yield();
    }
    while (xQueueReceive(xControlMessageQueue, &controlMessage, 0) == pdPASS)
    {
      if (controlMessage == ControlMessage::NODE_ONLINE)
      {
        if (currentSystemState != SystemState::WAIT_FOR_SHUTDOWN)
        {
          currentSystemState = SystemState::ON;
        }
      }
      if (controlMessage == ControlMessage::NODE_TIMEOUT)
      {
        mainRelay.setState(false);
        delay(CONFIG_RELAY_PULSE_MS);
        mainRelay.stopPulse();

        Serial.println("Received timeout message");

        currentSystemState = SystemState::OFF;
      }
      yield();
    }

    if (currentSystemState == SystemState::WAIT_FOR_SHUTDOWN)
    {
      for (pin_size_t pinShutdown : PINS_SHUTDOWN)
      {
        digitalWrite(pinShutdown, HIGH);
        delay(500);
        digitalWrite(pinShutdown, LOW);
        delay(500);
      }
    }

    yield();
  }
}