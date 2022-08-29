import math
m = 4
k = 256
n = 10
all_var = 0


def form(m, n):
    return math.factorial(n) / (math.factorial(m) * math.factorial(n-m))


for m in range(m, k):
    all_var += form(m, n)

print(all_var)
