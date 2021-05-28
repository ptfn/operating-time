from random import randint
from math import sqrt

while 1:
    x = randint(1,100)
    y = randint(1,100)
    z = randint(1,100)
    n = randint(2, 10)
    xy = sqrt((x**n) + (y**n))
    if xy == z:
        print('x:{} y:{} z:{} n:{}'.format(x, y, z, n))
