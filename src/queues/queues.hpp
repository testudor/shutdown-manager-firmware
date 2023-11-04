#ifndef QUEUES_HPP
#define QUEUES_HPP

#include <FreeRTOS.h>
#include <queue.h>

enum ControlMessage
{
  NODE_TIMEOUT,
  NODE_ONLINE
};

extern QueueHandle_t xControlMessageQueue;

struct InputEvent
{
  uint8_t keyCode;
  uint8_t eventType;
};

extern QueueHandle_t xInputEventQueue;

#endif