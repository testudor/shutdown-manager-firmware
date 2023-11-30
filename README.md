# Shutdown Manager Firmware

This is the firmware for the [Shutdown Manager Mainboard.](https://github.com/testudor/shutdown-manager-mainboard)

## Flashing

1. Install the PlatformIO extension in VS Code.
2. Open this project.
3. Configure (optional)
4. Upload!

## Configuration

Modify the file `src/config.hpp` to configure the firmware.

| Variable                            | Function                                                                                                       |
|-------------------------------------|----------------------------------------------------------------------------------------------------------------|
| CONFIG_NODE_TIMEOUT_MS              | How long to wait until the power is turned off. The timer is started, when the last node goes offline.         |
| CONFIG_RELAY_PULSE_MS               | Pulse duration when switching the relay. You shouldn't need to change this.                                    |
| CONFIG_LED_BRIGHTNESS               | Switch LED brightness from 0 to 255.                                                                           |
| CONFIG_COLOR_RED/CONFIG_COLOR_GREEN | PWM values which correspond to the two LED colors. Switch these values, if your cable is connected in reverse. |
