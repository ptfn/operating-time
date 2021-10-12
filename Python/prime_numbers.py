from time import sleep
from random import randrange

n = randrange(10,10000)
lim = int((n-1)/2)
arr = []

for i in range(1, lim):
    arr.append(i)

for i in range(1, len(arr)):
    for j in range(1, len(arr)):
        res = i+j+2*i*j
        if res <= len(arr):
            arr[res-1] = 0

for i in range(len(arr)):
    if arr [i] != 0:
        print("{}".format(2*arr[i]+1))
        sleep(0.05)