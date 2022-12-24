def fib(n):
    if n <= 2:
        return n
    else:
        return (fib(n-1) + fib(n-2))


def fib2(n):
    a, b = 0, 1
    for i in range(n-1):
        a, b = b, a + b
    return b


def main():
    print(fib2(10))


if __name__ == '__main__':
    main()
