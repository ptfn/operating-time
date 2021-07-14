import matplotlib.pyplot as plt
import random

class Point():
  def __init__(self, x, y):
    self.x = x
    self.y = y

X = [0]
Y = [0]

a = Point(random.randrange(-15, 15), random.randrange(-15, 15))
b = Point(random.randrange(-15, 15), random.randrange(-15, 15))
c = Point(random.randrange(-15, 15), random.randrange(-15, 15))
first = Point(random.randrange(-5, 5), random.randrange(-5, 5))


def dotPoint(p1:Point, p2:Point):
    if p1.x > p2.x: 
        x = ((p1.x - p2.x) / 2) + p2.x 
    else:
        x = ((p2.x - p1.x) / 2) + p1.x

    if p1.y > p2.y: 
        y = ((p1.y - p2.y) / 2) + p2.y
    else:
        y = ((p2.y - p1.y) / 2) + p1.y
    return Point(x,y)

for i in range(99999):
    random_dot = random.randrange(0,300)

    if random_dot >= 0 & random_dot <= 99:
        newp = dotPoint(p1 = a, p2 = first)
        first = newp
        X.append(newp.x);Y.append(newp.y)
    elif random_dot >= 100 & random_dot <= 200:
        newp = dotPoint(p1 = b, p2 = first)
        first = newp
        X.append(newp.x);Y.append(newp.y)
    elif random_dot >= 201 & random_dot <= 300:
        newp = dotPoint(p1 = c, p2 = first)
        first = newp
        X.append(newp.x);Y.append(newp.y)
    

plt.figure(figsize = [15,15])
plt.scatter(X,Y,color = 'g',marker = '.')
plt.show()