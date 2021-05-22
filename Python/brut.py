arr = ['1', '2', '3']
strn = []
res = []

for i in range(len(arr)):
    res.append(arr[i])
    strn = []
    strn.append(arr[i])
    for n in range(len(arr)):
        if arr[i] != arr[n]:
            if arr[n] not in strn:
                strn.append(arr[n])
    res.append(strn)

print(res)