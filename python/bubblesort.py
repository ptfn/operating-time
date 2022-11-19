from random import randint


def bubblesort(arr):
    for i in range(len(arr)):
        for j in range(len(arr)):
            if j != len(arr) - 1:
                if arr[j] > arr[j+1]:
                    arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr


def main():
    n = 100000
    arr = [randint(1, n) for i in range(n)]

    print(arr)
    print(bubblesort(arr))


if __name__ == '__main__':
    main()
