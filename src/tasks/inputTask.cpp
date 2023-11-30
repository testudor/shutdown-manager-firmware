#include "inputTask.hpp"

void onPowerButtonShortPress(uint8_t keycode)
{
  InputEvent data = {
      keycode,
      0};
  xQueueSendToBack(xInputEventQueue, (void *)&data, 0);
  Serial.println("sent short press.");
}

void onPowerButtonLongPress(uint8_t keycode)
{
  InputEvent data = {
      keycode,
      1};
  xQueueSendToBack(xInputEventQueue, (void *)&data, 1);
  Serial.println("sent long press.");
}

void inputTask(void *pvParameters)

{
  Button powerButton(0, PIN_POW_SW, 15, INPUT_PULLUP, true);

  powerButton.begin();

  pinMode(PIN_POW_SW, INPUT_PULLUP);

  powerButton.registerReleaseCallback(onPowerButtonShortPress);
  powerButton.registerLongPressCallback(1500, onPowerButtonLongPress);

  while (true)
  {
    powerButton.sample();
    yield();
  }
}
