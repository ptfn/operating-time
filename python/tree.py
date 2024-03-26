from turtle import *

bgcolor('white')
left(90)
speed(100)
color('black')
pensize(2)
title("Fractal Tree")


def draw(n):
    if (n < 5):

        return

    else:

        forward(n)
        left(30)
        draw(6 * n / 8)
        right(60)
        draw(6 * n / 8)
        left(30)
        backward(n)


draw(100)
done()
