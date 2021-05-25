import psutil as ps
import sys
import time

low = int(sys.argv[1])

while True:
    battery = ps.sensors_battery()
    persent = battery.percent
    power = battery.power_plugged
    
    if persent <= low:
        print("Low persent!")
    elif persent == 100:
        print("High persent!")
    elif power == False:
        print("Discharged")
    elif power == True:
        print("Charging ")
    time.sleep(5)
