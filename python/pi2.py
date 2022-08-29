def pi(n):
    res = 0
    for i in range(0, n):
        res += ((-1)**i) / (2 * i + 1)
    return res * 4


print(pi(1000000))
