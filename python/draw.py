import random
import math

new_user = []
old_user = []
win_user = []
all_user = []


def limition (arr):
    len_arr = len(arr)

    if len_arr <= 1:
        k = 100
    elif len_arr <= 5 or len_arr <= 10:
        k = 50
    elif len_arr >= 10:
        k = 15

    limit = math.floor((len_arr / 100) * k)
    return limit


def draw(arr):
    limit = limition(arr)
                                # <== Условие для рандома
    for i in range(0,limit):
        winner = random.choice(arr)
        win_user.append(winner)
        arr.remove(winner)
        print(winner)


def draw_new_or_old(arr_new, arr_old):
    limit_new = limition(arr_new)
    limit_old = limition(arr_old)
    limit = limit_new + limit_old
    new_percent = math.floor((limit / 100) * 20)
    old_percent = math.floor((limit / 100) * 80)
                                # <== Условие для рандома
    for i in range(0,new_percent):
        winner = random.choice(arr_new)
        win_user.append(winner)
        arr_new.remove(winner)
        print(winner)

    for i in range(0,old_percent):
        winner = random.choice(arr_old)
        win_user.append(winner)
        arr_old.remove(winner)
        print(winner)


while True:
    choice = int(input('Draw(1)/Add User(2)/Del Use(3)/Exit(4)/Mas(5):'))

    if choice == 1:

        if new_user != [] and old_user != []:
            pass
        elif new_user == [] and old_user == [] and win_user == []:
            print('no participants')

        elif new_user == [] and old_user == []:

                old_user = win_user.copy()
                win_user.clear()
                draw(old_user)

        elif old_user == []:
            if len(new_user) >= 1:
                draw(new_user)
            else:
                print('not enough participants')

        elif new_user == []:

            if len(old_user) >= 1:
                draw(old_user)
            else:
                print('not enough participants')

        else:
            print('No User')

    elif choice == 2:
        user = input('Name user:')
        new_user.append(user)
        all_user.append(user)

    elif choice == 3:
        user = input('Name user:')
        all_user.remove(user)

        if user in new_user:
            new_user.remove(user)
        elif user in old_user:
            old_user.remove(user)
        elif user in win_user:
            win_user.remove(user)
        else:
            print('No anywhere')

    elif choice == 4:
        break

    elif choice == 5:
        print('New:',new_user)
        print('Old:',old_user)
        print('Win:',win_user)
        print('All:',all_user)

    else:
        print('Error')
