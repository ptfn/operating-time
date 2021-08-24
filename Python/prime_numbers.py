def even(n):
    arr = []
    arr2 = []
    res = 0

    for i in range(1, n+1):
        arr.append(i)

    for i in range(1, len(arr)):
        for j in range(1, len(arr)):
            res = i+j+2*i*j
            if res <= len(arr):
                arr[res-1] = 0

    for i in range(len(arr)):
        if arr[i] != 0:
            arr2.append(2*arr[i]+1)

    return arr2

if __name__ == '__main__':
    print(even(100))