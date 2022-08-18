from time import sleep
from sys import argv

n = int(argv[1])
arr = [n]
iters = 0

while True: 
    if n == 1:
        iters += 1
        break

    elif n % 2 == 0:
        iters += 1
        n = round(n / 2)
        arr.append(n)
        print(n)

    elif n % 2 != 0:
        iters += 1
        n = round(3 * n + 1)
        arr.append(n)
        print(n)

    sleep(0.05)

print(f"\nIter\t{iters}\nMax\t{max(arr)}")