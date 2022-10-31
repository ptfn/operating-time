numStud = 202368
kol = 60

num = numStud % 10
print('вариант:', num)
print('номер заданий')

for i in range(kol-9):
    if(i % 5 == 0):
        print(i+num)
