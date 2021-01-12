import random
import hashlib
import time

Start_Time = time.time()
Password = ""
Correct_Password = "40bd001563085fc35165329ea1ff5c5ecbdbbeef"  # Нужный пароль
Length = 3 # Придумать как сделать длину
Chars = "0123456789"  # Алфавит из всего
Wrong_Passwords = []
All_Passwords = 0  # Все перебратые пароли

while True:

    Password = ""
    All_Passwords += 1

    for i in range(Length):
        Password += random.choice(Chars)  # Рандомный пароль
        Password_Hash = hashlib.sha1(str(Password).encode("ascii")).hexdigest()

    if Password_Hash not in Wrong_Passwords:

        if Password_Hash != Correct_Password:  # Несоотвествия пароля

            print(Password_Hash)
            Wrong_Passwords.append(Password_Hash)

        else:

            break

End_time = time.time() - Start_Time  # Время выполнения

print("Password Hash:", Password_Hash)
print("All Passwords:", All_Passwords)
print("Time:{} s".format(End_time))
