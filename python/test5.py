import notify2
import time
import sys


def main():
    notify2.init("Test")
    n = notify2.Notification("Hello")
    n.set_urgency(notify2.URGENCY_NORMAL)
    n.set_timeout(1000)

    while True:
        try:
            n.show()
            time.sleep(int(sys.argv[1]))

        except Exception as e:
            print(e)
            n.close()
            break


if __name__ == "__main__":
    main()
