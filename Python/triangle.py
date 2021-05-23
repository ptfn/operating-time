import matplotlib.pyplot as plt
import random

class Point():
  def __init__(self, x, y):
    self.x = x
    self.y = y

X = [0]
Y = [0]

a = Point(random.randrange(10, 50), random.randrange(10, 50))
b = Point(random.randrange(10, 50), random.randrange(10, 50))
c = Point(random.randrange(10, 50), random.randrange(10, 50))
first = Point(random.randrange(20, 40), random.randrange(20, 40))

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

for i in range(10000):
    random_dot = random.randrange(0,100)

    if random_dot > 0 & random_dot < 33:
        newp = dotPoint(p1 = a, p2 = first)
        first = newp
    if random_dot > 34 & random_dot < 67:
        newp = dotPoint(p1 = b, p2 = first)
        first = newp
    if random_dot > 68 & random_dot < 100:
        newp = dotPoint(p1 = c, p2 = first)
        first = newp
    X.append(newp.x);Y.append(newp.y)
    

plt.figure(figsize = [15,15])
plt.scatter(X,Y,color = 'g',marker = '.')
plt.show()