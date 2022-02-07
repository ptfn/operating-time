from math import factorial
e = 0
for i in range(0, 200):
    e += 1 / factorial(i)
print(e)