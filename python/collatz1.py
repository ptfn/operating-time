from sys import argv


def collatz(n):
    arr = []

    while True:
        if n not in arr:
            arr.append(int(n))
        else:
            break

        if n == 1:
            break

        elif n % 2 == 0:
            n = n / 2

        elif n % 2 != 0:
            n = 3 * n + 1

    return arr


def main():
    n = int(argv[1])
    arr = collatz(n)
    print(f"{n} -> {len(arr)}")
    print(sorted(arr))


if __name__ == '__main__':
    main()
