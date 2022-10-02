from random import randint

maxi = 10
arr = [randint(1, maxi) for i in range(10)]
res = [(arr.count(i), i) for i in range(1, maxi+1)]
print(f"{arr}\n{res}")
