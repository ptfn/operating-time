from turtle import *
color('black')
speed(100)
pensize(1)
while True:
    forward(100)
    left(100)
    if abs(pos()) < 1:
        break
done()