from random import randint
from math import sqrt

print("X\tY\tZ\tW")
while 1:
    x = randint(1,100)
    y = randint(1,100)
    z = randint(1,100)
    w = randint(1,100)

    xyz = (x**3)+(y**3)+(z**3)
    wn = w ** 3
    if xyz == wn:
        print("{}\t{}\t{}\t{}".format(x, y, z, w))