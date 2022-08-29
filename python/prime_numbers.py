arr = [i for i in range(0, 1000)]

for i in range(1, len(arr)):
    for j in range(1, len(arr)):
        res = i+j+2*i*j
        if res <= len(arr):
            arr[res-1] = 0

for i in range(len(arr)):
    if i + 1 == len(arr) and arr[i] != 0:
        print("{} \n".format(2*arr[i]+1), end="")
    elif i + 1 == len(arr):
        print("\n")
    elif arr[i] != 0:
        print("{} \t".format(2*arr[i]+1), end="")
