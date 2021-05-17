import sys

string = sys.argv[1]
alp = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/='

def encrypt(string):
    arr = []
    arr2 = []
    res = ''
    bite = ''
    string2 = ''

    for i in range(len(string)):
        bite = bin(ord(string[i]))
        bite = bite.replace('b','')
        arr.append(bite)

    # if len(arr) < 3:
    #     dif = 3 - int(len(arr))
    #     for n in range(0, dif):
    #         arr.append('00000000')

    for i in range(len(arr)):
        res += arr[i]

    lol = lambda lst, sz: [lst[i:i+sz] for i in range(0, len(lst), sz)]
    arr2 = lol(res, 6)

    for i in range(len(arr2)):
        leng = len(arr2[i])
        if leng < 6:
            dif = 6 - int(len(arr2[i]))
            for n in range(0, dif):
                arr2[i] += '0'

    for i in range(len(arr2)):
        arr2[i] = '00' + arr2[i]

    for i in range(len(arr2)):
        arr2[i] = int(arr2[i], base=2)
        arr2[i] = alp[int(arr2[i])]

    for i in range(len(arr2)):
        string2 += arr2[i]

    return arr

print(encrypt(string))
