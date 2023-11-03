#include "ledTask.hpp"

void ledTask(void *pvParameters)
{
  SimpleLedMixer powerButtonLed(PIN_LED_COLOR, PIN_LED_BRIGHTNESS);
  powerButtonLed.begin();

  while (true)
  {
    switch (currentSystemState)
    {
    case SystemState::OFF:
      powerButtonLed.setBrightness(0);
      break;
    case SystemState::WAIT_FOR_BOOT:
      powerButtonLed.setBrightness(Wave::generateSine(xTaskGetTickCount(), portTICK_RATE_MS, 0, CONFIG_LED_BRIGHTNESS, 600));
      powerButtonLed.setColorMix(CONFIG_COLOR_GREEN);
      break;
    case SystemState::ON:
      powerButtonLed.setBrightness(CONFIG_LED_BRIGHTNESS);
      powerButtonLed.setColorMix(CONFIG_COLOR_GREEN);
      break;
    case SystemState::WAIT_FOR_SHUTDOWN:
      powerButtonLed.setBrightness(Wave::generateSine(xTaskGetTickCount(), portTICK_RATE_MS, 0, CONFIG_LED_BRIGHTNESS, 600));
      powerButtonLed.setColorMix(CONFIG_COLOR_RED);
      break;
    }

    yield();
  }
}