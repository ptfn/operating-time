import random
Symbols = "!@#$%^&*=<>0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
Length = int(input("Введите длину пароля:"))
Num_pass = int(input("Введите число паролей"))
for n in range(Num_pass):
    password = ""
    for i in range(Length):
        password += random.choice(Symbols)
    print(password)