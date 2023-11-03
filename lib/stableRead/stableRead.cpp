#include "stableRead.hpp"
#include <Arduino.h>

void StableRead::begin()
{
  pinMode(pin, mode);
}

void StableRead::sample()
{
  curState = digitalRead(pin);

  if (invert)
  {
    curState = !curState;
  }

  if (curState == HIGH)
  {
    curSamples++;
  }
  else if (curState == LOW)
  {
    curSamples = 0;
    sentHigh = false;

    if (changeCallback != NULL && !sentLow)
    {
      changeCallback(LOW);
      sentLow = true;
    }
  }

  if (curSamples >= samples && changeCallback != NULL && !sentHigh)
  {
    changeCallback(HIGH);
    sentHigh = true;
    sentLow = false;
  }
}

PinStatus StableRead::poll()
{
  if (curSamples >= samples)
  {
    return HIGH;
  }
  else
  {
    return LOW;
  }
}

void StableRead::registerChangeCallback(void (*callback)(PinStatus state))
{
  changeCallback = callback;
}