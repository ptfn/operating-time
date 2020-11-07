import random
import time

Start_Time = time.time()
Password = ""
Correct_Password = "2020"  # Нужный пароль
Length = len(Correct_Password)
Chars = "0123456789"  # Алфавит из всего
Wrong_Passwords = []
All_Passwords = 0  # Все перебратые пароли

while True:

    Password = ""
    All_Passwords += 1

    for i in range(Length):
        Password += random.choice(Chars)  # Рандомный пароль

    if Password not in Wrong_Passwords:

        if Password != Correct_Password:  # Несоотвествия пароля

            print(Password)
            Wrong_Passwords.append(Password)

        else:

            break

End_time = time.time() - Start_Time  # Время выполнения

print("Password:", Password)
print("All Passwords:", All_Passwords)
print("Time:{} s".format(End_time))
