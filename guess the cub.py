import random
import math

ran_num = random.randrange(10,101)
ran_cub = pow(ran_num,3)
print("Загаданное число:",ran_cub)

while True:

    guess = int(input('Отгадайте число:'))
    guess_cub = pow(guess,3)

    if guess_cub == ran_cub:

        print('--Победа--')
        print("Загаданное число:",ran_num)
        break

    else:

        print('--Проигрыш--')
        print("Загаданное число:",ran_num)
        break   