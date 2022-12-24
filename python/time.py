from time import time, sleep
from enum import Enum
from os import system
import notify2


def format(t):
    milliseconds = int(t % 60)
    sec = (t - milliseconds) / 60
    minutes = int(sec // 60)
    seconds = int(sec % 60)

    m, s, ml = str(minutes), str(seconds), str(milliseconds)

    if (len(m) < 2):
        m = '0' + m
    if (len(s) < 2):
        s = '0' + s
    if (len(ml) < 2):
        ml = '0' + ml

    return f"{m}:{s}:{ml}"


def work():
    notify2.init("Work")
    n = notify2.Notification("Go to work mode!")
    n.set_urgency(notify2.URGENCY_NORMAL)
    n.set_timeout(5000)
    n.show()


def chill():
    notify2.init("Chill")
    n = notify2.Notification("Go to chill mode!")
    n.set_urgency(notify2.URGENCY_NORMAL)
    n.set_timeout(5000)
    n.show()


def main():
    START = time()
    state = Enum("state", "work chill", start=1)
    TRANSITION = state.work

    while True:
        timen = time() - START
        if timen/60 >= 25 and TRANSITION == state.work:
            TRANSITION = state.chill
            START = time()
            chill()

        elif timen/60 >= 5 and TRANSITION == state.chill:
            TRANSITION = state.work
            START = time()
            work()

        print(format(timen))
        sleep(0.1)
        system('clear')


if __name__ == "__main__":
    main()
