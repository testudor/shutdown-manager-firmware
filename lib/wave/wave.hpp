#ifndef WAVE_HPP
#define WAVE_HPP

namespace Wave
{
  float generateSine(long ticks, int msPerTick, float lowerBound, float upperBound, int period);

  float generateSquare(long ticks, int msPerTick, float lowerBound, float upperBound, int period);
};

#endif