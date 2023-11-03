#ifndef PINS_HPP
#define PINS_HPP

#include <Arduino.h>

const pin_size_t PIN_HEARTBEAT_1 = D7;
const pin_size_t PIN_HEARTBEAT_2 = D9;
const pin_size_t PINS_HEARTBEAT[2] = {PIN_HEARTBEAT_1, PIN_HEARTBEAT_2};

const pin_size_t PIN_SHUTDOWN_1 = D8;
const pin_size_t PIN_SHUTDOWN_2 = D10;
const pin_size_t PINS_SHUTDOWN[2] = {PIN_SHUTDOWN_1, PIN_SHUTDOWN_2};

const pin_size_t PIN_POW_SW = D0;
const pin_size_t PIN_LED_BRIGHTNESS = D1;
const pin_size_t PIN_LED_COLOR = D2;

const pin_size_t PIN_RELAY_TRIG = D3;
const pin_size_t PIN_RELAY_DIR = D4;

const pin_size_t PIN_RGB_ENABLE = 11;
const pin_size_t PIN_RGB_DATA = 12;

#endif