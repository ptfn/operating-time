import random
a = random.randrange(1000000,10000000)
b = random.randrange(1000000,10000000)
for i in range(10000000):
    a = a + b
    b = a + b
fi = b / a
print(fi)