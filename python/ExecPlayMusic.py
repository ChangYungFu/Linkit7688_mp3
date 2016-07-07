import os
import time
os.system("curl -k https://raw.githubusercontent.com/ChangYungFu/Audio/master/0006_%E5%9C%9F%E8%80%B3%E5%85%B6%E9%80%B2%E8%A1%8C%E6%9B%B2.mp3  |  madplay - -a+5 -o wave:- | aplay -D plughw:1")
time.sleep(5)
print("killall curl")
os.system("killall curl")
