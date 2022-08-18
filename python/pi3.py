import time

def form(k):
    return 1/(16**k) * ((4/(8*k+1)) - (2/(8*k+4)) - (1/(8*k+5)) - (1/(8*k+6)))

def pi(n):
    return sum(list([form(i) for i in range(n)]))

print(f"{pi(100)}")