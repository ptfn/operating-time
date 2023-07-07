import psutil as ps
import sys
import time

low = int(sys.argv[1])
time_period = float(sys.argv[2])

while True:
    battery = ps.sensors_battery()
    persent = round(battery.percent)
    power = battery.power_plugged

    if persent <= low:
        print("Low persent!")
    elif persent == 100:
        print("High persent!")
    elif power == False:
        print("Discharged ({}%)".format(persent))
    elif power == True:
        print("Charging ({}%)".format(persent))
        
    time.sleep(time_period)
