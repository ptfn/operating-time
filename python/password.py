import random
import time

Start_Time = time.time()
Password = ""
Correct_Password = "1234"
Length = len(Correct_Password)
Chars = "0123456789"
Wrong_Passwords = []
All_Passwords = 0

while True:
    Password = ""
    All_Passwords += 1

    for i in range(Length):
        Password += random.choice(Chars)

    if Password not in Wrong_Passwords:
        if Password != Correct_Password:
            print(Password)
            Wrong_Passwords.append(Password)
        else:
            break

End_time = time.time() - Start_Time
print("Password:", Password)
print("All Passwords:", All_Passwords)
print("Time:{} s".format(End_time))
