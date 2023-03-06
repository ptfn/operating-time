import math
import sys


def pow(n: int, m: int) -> int:
    arr = []
    res = 1

    while True:
        if m % 2 != 0:
            arr.append(n)

        if m == 1:
            break

        m = m // 2
        n = n ** 2

    return math.prod(arr)


def main():
    a = int(sys.argv[1])
    b = int(sys.argv[2])
    print(pow(a, b))
    

if __name__ == '__main__':
    main()

