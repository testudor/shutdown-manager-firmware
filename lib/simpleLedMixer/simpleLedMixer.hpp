#ifndef SIMPLE_LED_MIXER_HPP
#define SIMPLE_LED_MIXER_HPP

#include <Arduino.h>

class SimpleLedMixer
{
public:
  SimpleLedMixer(pin_size_t colorPin, pin_size_t brightnessPin) : colorPin(colorPin), brightnessPin(brightnessPin) {}

  void begin();
  void setColorMix(uint8_t color);
  void setBrightness(uint8_t brightness);

private:
  pin_size_t colorPin;
  pin_size_t brightnessPin;
};

#endif