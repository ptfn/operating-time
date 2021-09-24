from random import randint
from math import sqrt

print("X\tY\tZ\tN")
while 1:
    x = randint(2,1000)
    y = randint(2,1000)
    z = randint(2,1000)
    n = 2

    xy = ((x**n) + (y**n))
    zn = z**n
    if xy == zn:
        print("{}\t{}\t{}\t{}".format(x, y, z, n))
