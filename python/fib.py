def fib(n):
    if n <= 2:
        return n
    else:
        return (fib(n-1) + fib(n-2))


def main():
    print(fib(10))


if __name__ == '__main__':
    main()
