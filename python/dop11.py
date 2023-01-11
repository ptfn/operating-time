MONTH = [31, 28, 31, 30,
         31, 30, 31, 31,
         30, 31, 30, 31]


# Функция для распределение строки ввода
def input_year(s):
    if s[4] != '.' and s[4] != '/':
        d, m, y = int(s[0:2]), int(s[3:5]), int(s[6:])
    else:
        y, m, d = int(s[0:4]), int(s[5:7]), int(s[8:])
    return d, m, y


# Функция для вычисленния весокосного года
def leap_year(y):
    if y % 4 == 0 and y % 100 != 0 or y % 400 == 0:
        return True
    else:
        return False


# Функция для подсчёта количество дней
def number_days(d, m, y):
    num_day = 0

    if leap_year(y):
        MONTH[1] = 29

    # Суммирование количество дней от 1999 до y
    for i in range(1999, y):
        if leap_year(i):
            num_day += 366
        else:
            num_day += 365

    # Суммирование до определенного месяца m
    for j in range(m-1):
        num_day += MONTH[j]

    num_day += d
    num_day -= 1

    return num_day


# Функция для определения дня недели
def day(n):
    if n % 7 == 0:
        print("ПТ")
    elif n % 7 == 1:
        print("СБ")
    elif n % 7 == 2:
        print("ВС")
    elif n % 7 == 3:
        print("ПН")
    elif n % 7 == 4:
        print("ВТ")
    elif n % 7 == 5:
        print("СР")
    elif n % 7 == 6:
        print("ЧТ")


if __name__ == "__main__":
    s = "11/11/2222"
    d, m, y = input_year(s)
    day(number_days(d, m, y))
