import random
num = int(input("Введите до скольки загадывать число:"))
ran_num = random.randrange(0,num)
chance = int(input("Сколько шансов:"))
print("--Число загадано--")
for i in range (0,chance):
  guess = int(input("Отгадайте число:"))
  if ran_num > guess:
    print("Больше")
  elif ran_num < guess:
    print("Меньше")
  elif ran_num == guess:
    print("--Вы угадали число--")
    print("Загаданое число было:",ran_num)
    break
else:
  print("--Вы не угадали число--")
  print("Загаданое число было:",ran_num)