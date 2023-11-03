#ifndef TASK_HANDLES_HPP
#define TASK_HANDLES_HPP

#include <FreeRTOS.h>
#include <task.h>

// xTaskHandle Handle_rgbTask;
extern xTaskHandle Handle_ledTask;
extern xTaskHandle Handle_nodeWatchdogTask;
// xTaskHandle Handle_relayTask;
extern xTaskHandle Handle_controlTask;
extern xTaskHandle Handle_inputTask;

#endif