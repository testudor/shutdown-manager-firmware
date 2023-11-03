#include "button.hpp"
#include <Arduino.h>

void Button::begin()
{
    pinMode(pin, mode);
}

void Button::sample()
{
    curState = digitalRead(pin);

    if (invert)
    {
        curState = !curState;
    }

    if (curState)
    {
        curSamples++;

        if (pressStartTime == 0)
        {
            pressStartTime = millis();
        }
        else
        {
            curTime = millis();

            if (curTime - pressStartTime > delayTime && longPressCallback != NULL && sentLongPress == false)
            {
                longPressCallback(keycode);
                sentLongPress = true;
            }
        }
    }
    else
    {
        if (sentPress)
        {

            if (releaseCallback != NULL && !sentLongPress)
            {
                releaseCallback(keycode);
            }

            sentPress = false;
        }

        curSamples = 0;
        pressStartTime = 0;

        sentLongPress = false;
    }

    if (curSamples >= samples && !sentPress)
    {
        sentPress = true;

        if (pressCallback != NULL)
        {
            pressCallback(keycode);
        }
    }
}

void Button::registerPressCallback(void (*callback)(uint8_t keycode))
{
    pressCallback = callback;
}

void Button::registerReleaseCallback(void (*callback)(uint8_t keycode))
{
    releaseCallback = callback;
}

void Button::registerLongPressCallback(unsigned long t, void (*callback)(uint8_t keycode))
{
    delayTime = t;
    longPressCallback = callback;
}