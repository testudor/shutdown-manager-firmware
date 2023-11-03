#ifndef BISTABLE_RELAY_HPP
#define BISTABLE_RELAY_HPP

#include <Arduino.h>

class BistableRelay
{
public:
  BistableRelay(pin_size_t dirPin, pin_size_t trigPin, bool invertDir) : dirPin(dirPin), trigPin(trigPin), invertDir(invertDir) {}

  void begin();
  void setState(bool state);
  void stopPulse();

private:
  pin_size_t dirPin;
  pin_size_t trigPin;

  bool invertDir;

  bool curState;
};

#endif