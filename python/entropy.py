import sys
import math
import random


def read_file(name):
    # For byte
    file = open(f'{name}', 'r')
    arr = file.readlines()
    return ''.join(arr)


def create_arr(string):
    char = {}
    for i in range(len(string)):
        try:
            char[string[i]] += 1
        except Exception:
            char[string[i]] = 1
    arr = [char[i] for i in char]
    return arr


def entropy(arr):
    total = sum(arr)
    entropy = 0
    for i in range(len(arr)):
        p = arr[i] / total
        if p > 0:
            entropy -= p * math.log(p, 2)
    return entropy / 8 * 100
    # entropy (0-8) entropy / 8 (0-1) entropy / 8 * 100(0-100)


def entropy2(arr):
    return round(sum(arr) * math.log2(len(arr)), 2)


def level(num):
    if num < 37.5:
        return 'Bad'
    elif num < 40:
        return 'Weak'
    elif num < 50:
        return 'Good'
    else:
        return 'Excellent'


def level2(num):
    if num < 30:
        return txt_rd('Bad')
    elif num < 50:
        return txt_yel('Weak')
    elif num < 70:
        return txt_grn('Good')
    else:
        return txt_grn('Excellent')


def main():
    string = read_file(sys.argv[1])
    arr = create_arr(string)
    ent = entropy1(arr)
    lvl = level(ent)
    print(ent, lvl)


if __name__ == '__main__':
    main()
