def happy_num(n):
    a = []
    m = 2
    j = 0
    
    for i in range(2,n):
        a.append(i)

    a[0] = 0

    while m < n:
        if a[m] != 0:
            j = m * 2
        else:
            m += 1
        
        while j < n:
            a[j] = 0
            j = j + m
    return a
print(happy_num(30))



