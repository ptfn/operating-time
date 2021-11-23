arr = []

def fun(num):
    if num not in arr:
        arr.append(num)
        print(arr)

fun(4)
fun(4)
fun(3)