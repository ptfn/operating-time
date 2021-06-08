from random import randint
from math import sqrt

while 1:
    x = randint(2,1000)
    y = randint(2,1000)
    z = randint(2,1000)
    n = 2 # randint(3, 5)
    
    xy = ((x**n) + (y**n))
    zn = z**n
    if xy == zn:
        print('x:{} y:{} z:{} n:{}'.format(x, y, z, n))