from sys import argv
from time import sleep

n = int(argv[1])
arr = []

for i in range(1,n):
    while True:
        if i == 1:
            break

        elif i % 2 == 0:
            if i not in arr:
                arr.append(int(i))
            else:
                break
            i = i / 2

        elif i % 2 != 0:
            if i not in arr:
                arr.append(int(i))
            else:
                break
            i = 3 * i + 1


        else:
            break
    
        sleep(0.001)

arr.sort()

print(f"{n} -> {len(arr)}")
print(f"{arr}")