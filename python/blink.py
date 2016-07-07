#blink don't input chinese font
import mraa
import time
# Refer to the pinout digram for the GPIO number to silk print mapping # in this example the number 44 maps to Wi-Fi LED.
pin = mraa.Gpio(44)    #44 wifi orange light
pin.dir(mraa.DIR_OUT)
while True:  # LED
   pin.write(1)
   time.sleep(0.2)  # wait for a second
   print ("1")
   pin.write(0)
   time.sleep(0.1)
   print("0")
