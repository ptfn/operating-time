from time import sleep
from sys import argv

n = int(argv[1])
sn = n
arr = [n]
iters = 0

while True: 
    if n == 1:
        iters += 1
        break
    elif n % 2 == 0:
        iters += 1
        n = n / 2
        arr.append(n)
        print(n)
    elif n % 2 != 0:
        iters += 1
        n = 3 * n + 1
        arr.append(n)
        print(n)
    else:
        break
    sleep(0.1)

print("\nNum:{}\nIter:{}\nMax:{}".format(sn, iters, max(arr)))