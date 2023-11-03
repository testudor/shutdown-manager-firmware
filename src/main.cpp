#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

#include "../lib/button/button.hpp"
#include "../lib/wave/wave.hpp"
#include "../lib/stableRead/stableRead.hpp"

#include "./state/globalState.hpp"
#include "./tasks/taskHandles.hpp"
#include "./tasks/nodeWatchdogTask.hpp"
#include "./tasks/inputTask.hpp"
#include "./tasks/ledTask.hpp"
#include "./tasks/controlTask.hpp"

#include "pins.hpp"

void setup()
{
  Serial.begin(115200);

  Serial.println("INIT");

  xTaskCreate(ledTask, "LED", configMINIMAL_STACK_SIZE * 2, NULL, 1, &Handle_ledTask);
  xTaskCreate(nodeWatchdogTask, "NODE", configMINIMAL_STACK_SIZE * 2, NULL, 1, &Handle_nodeWatchdogTask);
  xTaskCreate(inputTask, "INPUT", configMINIMAL_STACK_SIZE * 2, NULL, 1, &Handle_inputTask);
  xTaskCreate(controlTask, "CTRL", configMINIMAL_STACK_SIZE * 2, NULL, 1, &Handle_controlTask);
}

void loop()
{
}