from random import randint

print("X\tY\tZ")
while 1:
    x = randint(2, 1000)
    y = randint(2, 1000)
    z = randint(2, 1000)
    n = 2

    xy = ((x**n) + (y**n))
    zn = z**n
    if xy == zn:
        print(f"{x}\t{y}\t{z}")
