import serial
import subprocess, sys
s = None
def setup():
	global s
	# open serial COM port to /dev/ttyS0, which maps to UART0(D0/D1)
	# the baudrate is set to 57600 and should be the same as the one
	# specified in the Arduino sketch uploaded to ATmega32U4.
	s = serial.Serial("/dev/ttyS0", 57600)
setup()
while True:
	line=s.readline()
	print("arduino:",line)
    pingPopen = subprocess.Popen(args=line, shell=True)
