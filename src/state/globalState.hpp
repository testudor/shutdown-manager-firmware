#ifndef GLOBAL_STATE_HPP
#define GLOBAL_STATE_HPP

#include <FreeRTOS.h>
#include <task.h>

enum SystemState
{
  OFF,
  ON,
  WAIT_FOR_SHUTDOWN,
  WAIT_FOR_BOOT
};

extern volatile SystemState currentSystemState;

#endif