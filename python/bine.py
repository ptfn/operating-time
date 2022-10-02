from math import sqrt


def fib(n):
    fi = (1 + sqrt(5)) / 2
    res = ((fi ** n) - ((-fi) ** (-n))) / ((2 * fi) - 1)
    return round(res, 0)


if __name__ == '__main__':
    print(fib(50))
