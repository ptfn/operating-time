def find_even_nums(num):
    arr = []
    for i in range(1, num + 1):
        if i % 2 == 0:
            arr.append(i)
    return arr


print(find_even_nums(10))
