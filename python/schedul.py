import schedule
import time

def sum1(a):
    print(a + 2)

schedule.every(5).seconds.do(sum1, a=2)

while True:
    schedule.run_pending()
    time.sleep(1)