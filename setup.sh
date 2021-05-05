#!/usr/bin/env bash

ARDUINO_TTY=$1
CAN_INTERFACE=can0

slcan_attach -f -s6 -o $ARDUINO_TTY
slcand -S 115200 $1 $CAN_INTERFACE
ip link set up $CAN_INTERFACE
