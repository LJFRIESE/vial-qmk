# Weekinro 360 Fix

Weekinro produces a split keyboard based onthe Kinesis 360 profile. They do not
open-source the QMK, and their firmware has severe ghosting. This fixes that issue.

I have no worked out how to implement the ST7789 lcd dongle screen that comes with their
product. They use a custom PCB, so I have no idea how to identify the correct pins.

With the fix in hand, I'm pretty happy with the keyboard.

## Notes

These configuration files were based off the [Mitosis](https://github.com/mattdibi/redox-w-firmware)

The original developer: https://github.com/weekinro

The product: https://www.aliexpress.com/w/wholesale-WK-keyboard.html
