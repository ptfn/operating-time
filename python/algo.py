numStud = 202331
j = 1

num = numStud % 10
print('Вариант:', num)
print('Номер\tЗадание')

for i in range(0, (104-9)):
    if(i % 5 == 0):
        print(f"{j}\t{num + i}")
        j += 1
