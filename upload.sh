#!/bin/bash
# upload.sh
#
# Use this script to upload sketch to Arduino Uno

arduino-cli upload --port /dev/ttyACM0 --fqbn arduino:avr:uno
