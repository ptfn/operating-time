import random
from math import sqrt

while 1:

    x = random.randint(1,1000)
    y = random.randint(1,1000)
    z = random.randint(1,1000)

    xy = sqrt((x**2) + (y**2))

    if xy == z:
        print('x:{} y:{} z:{}'.format(x, y, z))
