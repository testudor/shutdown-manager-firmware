#ifndef NODE_WATCHDOG_HPP
#define NODE_WATCHDOG_HPP

#include <Arduino.h>
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

#include "taskHandles.hpp"
#include "../queues/queues.hpp"
#include "../state/globalState.hpp"

#include "../pins.hpp"
#include "../config.hpp"

void nodeWatchdogTask(void *pvParameters);

#endif