#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <Arduino.h>

class Button
{
public:
    Button(uint8_t keycode, uint8_t pin, uint8_t samples, uint8_t pinMode, bool invert) : keycode(keycode), pin(pin), samples(samples), mode(mode), invert(invert) {}

    void begin();

    void sample();

    void registerPressCallback(void (*callback)(uint8_t keycode));

    void registerReleaseCallback(void (*callback)(uint8_t keycode));

    void registerLongPressCallback(unsigned long t, void (*callback)(uint8_t keycode));

private:
    void (*pressCallback)(uint8_t keycode) = NULL;
    void (*releaseCallback)(uint8_t keycode) = NULL;
    void (*longPressCallback)(uint8_t keycode) = NULL;

    uint8_t keycode;
    unsigned long delayTime;

    uint8_t pin;
    uint8_t samples;
    uint8_t mode;
    bool invert;

    bool curState;
    uint8_t curSamples;
    unsigned long curTime;
    unsigned long pressStartTime;

    bool sentLongPress;
    bool sentPress;
};

#endif