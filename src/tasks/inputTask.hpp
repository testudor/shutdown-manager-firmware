#ifndef INPUT_TASK_HPP
#define INPUT_TASK_HPP

#include <Arduino.h>
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

#include "taskHandles.hpp"
#include "../queues/queues.hpp"

#include "../lib/button/button.hpp"

#include "../pins.hpp"
#include "../config.hpp"

void inputTask(void *pvParameters);

#endif