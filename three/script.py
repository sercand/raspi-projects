import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)  # set board mode to Broadcom

GPIO.setup(37, GPIO.OUT)  # set up pin 17

GPIO.output(37, 1)  # turn on pin 17

time.sleep(1)
GPIO.output(37,0)

GPIO.cleanup()
