import time

n = 1650
arr = []

for i in range(1, n+1):
    arr.append(i)

for i in range(1, len(arr)):
    for j in range(1, len(arr)):
        res = i+j+2*i*j
        if res <= len(arr):
            arr[res-1] = 0

for i in range(len(arr)):
    if (2*arr[i]+1) == 1033:
        print(2*arr[i]+1)
        time.sleep(2)
    elif (2*arr[i]+1) == 3301:
        print(2*arr[i]+1)
        time.sleep(2)
    elif arr[i] != 0:
        print(2*arr[i]+1)
        time.sleep(0.05)