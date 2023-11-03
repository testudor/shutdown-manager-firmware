#include "simpleLedMixer.hpp"

void SimpleLedMixer::begin()
{
  pinMode(colorPin, OUTPUT);
  pinMode(brightnessPin, OUTPUT);
}

void SimpleLedMixer::setColorMix(uint8_t color)
{
  analogWrite(colorPin, color);
}

void SimpleLedMixer::setBrightness(uint8_t brightness)
{
  analogWrite(brightnessPin, brightness);
}