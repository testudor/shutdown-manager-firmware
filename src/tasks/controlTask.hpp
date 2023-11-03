#ifndef CONTROL_TASK_HPP
#define CONTROL_TASK_HPP

#include <Arduino.h>
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

#include "taskHandles.hpp"
#include "../queues/queues.hpp"
#include "../state/globalState.hpp"

#include "../lib/button/button.hpp"
#include "../lib/bistableRelay/bistableRelay.hpp"

#include "../pins.hpp"
#include "../config.hpp"

void controlTask(void *pvParameters);

#endif