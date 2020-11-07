import random
throws = int(input('Сколько раз вы хотите бросков:'))
while True:
  num_sum = 0
  for i in range (0,throws):
    num_one = random.randrange(1,7)
    num_sum += num_one
    print( num_one , end= " " )
  print("")
  print('Сумма бросков:',num_sum)
  print('--Игра--')
  select = int(input("Продольжить(1) или закончить(2):"))
  if select == 1:
    continue
  elif select == 2:
    break