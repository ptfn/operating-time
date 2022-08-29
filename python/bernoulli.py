from math import factorial as fac
from sys import argv


def comb(n, k):
    return fac(n) / (fac(k) * fac(n-k))


def berm(n):
    arr = [1]

    for i in range(1, n+1):
        res = 0
        for k in range(1, i+1):
            res += comb(i + 1, k + 1) * arr[i-k]
        res *= (-1)/(i+1)
        arr.append(res)
    return arr


print(berm(int(argv[1])))
