#ifndef LED_TASK_HPP
#define LED_TASK_HPP

#include <Arduino.h>
#include <FreeRTOS.h>
#include <task.h>

#include "taskHandles.hpp"
#include "../state/globalState.hpp"

#include "../lib/simpleLedMixer/simpleLedMixer.hpp"
#include "../lib/wave/wave.hpp"

#include "../pins.hpp"
#include "../config.hpp"

void ledTask(void *pvParameters);

#endif