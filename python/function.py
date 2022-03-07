import matplotlib.pyplot as plt
from math import *

def fun(n):
    return cos(2*pi*n)

def main():
    X = []
    Y = []

    for x in range(1,1000):
        if x != 0:
            y = fun(x)
            X.append(x), Y.append(y)

    plt.plot(X,Y)
    plt.show()

if __name__ == '__main__':
    main()