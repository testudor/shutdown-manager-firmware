#include "wave.hpp"
#include <Arduino.h>

float Wave::generateSine(long ticks, int msPerTick, float lowerBound, float upperBound, int period)
{
  float ms = (float)ticks * (float)msPerTick;

  float peakToPeak = abs(lowerBound) + abs(upperBound);

  float offset = (upperBound - lowerBound) / 2;

  return ((sin(((ms * M_PI) / 0.5) / period)) / 2) * peakToPeak + offset;
}

float Wave::generateSquare(long ticks, int msPerTick, float lowerBound, float upperBound, int period)
{
  float ms = (float)ticks * (float)msPerTick;

  float peakToPeak = abs(lowerBound) + abs(upperBound);

  float offset = (upperBound - lowerBound) / 2;

  float wavePos = (int)ms % period;

  if (wavePos < period / 2)
  {
    return lowerBound;
  }
  else
  {
    return upperBound;
  }
}
