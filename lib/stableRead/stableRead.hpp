#ifndef STABLE_READ_HPP
#define STABLE_READ_HPP

#include <Arduino.h>

class StableRead
{
public:
  StableRead(uint8_t pin, uint8_t samples, uint8_t pinMode, bool invert) : pin(pin), samples(samples), mode(mode), invert(invert) {}

  void begin();

  void sample();

  PinStatus poll();

  void registerChangeCallback(void (*callback)(PinStatus state));

private:
  void (*changeCallback)(PinStatus state) = NULL;

  uint8_t pin;
  uint8_t samples;
  uint8_t mode;
  bool invert;

  bool curState;
  uint8_t curSamples;

  bool sentHigh;
  bool sentLow;
};

#endif