#include "bistableRelay.hpp"

void BistableRelay::begin()
{
  pinMode(dirPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
}

void BistableRelay::setState(bool state)
{
  if (state != curState)
  {
    if (invertDir)
    {
      state = !state;
    }
    curState = state;
    digitalWrite(dirPin, state);
    digitalWrite(trigPin, HIGH);
  }
}

void BistableRelay::stopPulse()
{
  digitalWrite(trigPin, LOW);
}