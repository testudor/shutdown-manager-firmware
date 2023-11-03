#ifndef QUEUES_HPP
#define QUEUES_HPP

#include <FreeRTOS.h>
#include <queue.h>

enum ControlMessage
{
  NODE_TIMEOUT,
  NODE_ONLINE
};

extern QueueHandle_t xInputEventQueue;
extern QueueHandle_t xControlMessageQueue;

#endif