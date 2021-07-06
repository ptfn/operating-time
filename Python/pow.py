def pow(n, m):
    arr = []
    res = 1
    while True:
        if m % 2 != 0:
            arr.append(n)
        if m == 1:
            break
        m = m // 2
        n = n ** 2
    for i in range(len(arr)):
        res *= arr[i]
    return res

if __name__ == '__main__':
    print(pow(102, 100))