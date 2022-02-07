def brut_list(arr):
    res = []
    # str = ''
    for i in range(len(arr)):
        for k in range(len(arr)):
            res.append(arr[k])
    return res

arr = ['1','2','3']
print(brut_list(arr))