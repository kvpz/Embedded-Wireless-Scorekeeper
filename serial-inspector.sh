#!/bin/bash
#
# serial-inspector.sh
#
# Use this script to inspect serial output from the Arduino.
# This is useful for debugging.

device_file=/dev/ttyACM0
baud_rate=9600 # does not work even though makefile
stty -F $device_file $baud_rate raw -clocal -echo
cat $device_file
