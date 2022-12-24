from math import sqrt
from sys import argv


def sqrt_num(n):
    arr = [sqrt(i) for i in range(1,n+1)]
    return list(filter(lambda x: x.is_integer(), arr))


def main():
    n = int(argv[1])
    arr = sqrt_num(n)
    print(f"All\t{n}\nSqrt\t{len(arr)}")


if __name__ == "__main__":
    main()
