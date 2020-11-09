def fib (n):
    if n <= 2:
        return n
    else:
        return(fib(n-1)+ fib(n-2))
print(fib(40))
# def Fi (n):
#     if n <= 2:
#         return n
#     else:
#         return(fib(n-1) / fib(n-2))
# print(Fi(25))