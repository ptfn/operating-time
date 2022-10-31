import random


def one_two():
    return random.randint(1, 2)


def one_two_three():
    arr = [(1,1,1), (1,1,2), (1,1,3), (1,2,1), (1,2,2), (1,2,3), (1,3,1), (1,3,2), (1,3,3),
           (2,1,1), (2,1,2), (2,1,3), (2,2,1), (2,2,2), (2,2,3), (2,3,1), (2,3,2), (2,3,3),
           (3,1,1), (3,1,2), (3,1,3), (3,2,1), (3,2,2), (3,2,3), (3,3,1), (3,3,2), (3,3,3)]

    num = arr.count((one_two(), one_two(), one_two()))
    print(one_two())

    if 1 <= num <= 9:
        return 1
    elif 10 <= num <= 18:
        return 2
    else:
        return 3


def main():
    print(one_two_three())


if __name__ == '__main__':
    main()