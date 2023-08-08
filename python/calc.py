expr = input()                        # вводим строку - математическое выражение
exprss = list(expr)
 
                                             # Инициализируем три списка
stack = []                                   # Стэк
priority = []                                # Приоритет операции
rpn = []                                     # rpn или reverse polish notation (обратная польская запись)
 
operation = ["+", "-", "*", "/", "^", "(", ")"]
 
for i in exprss:
 
    if i.isdigit():                          # Если символ из введенной строки - цифра, то добавляем ее в список rpn
        rpn.append(i)                     
 
    if i in operation:                       # Если символ из введенного выражения есть в списке operation, то
 
        if i == '+' or i == '-':               # Выставляем приоритет символа операции в список priority
            priority.append('2')
        elif i == '*' or i == '/':
            priority.append('3')
        elif i == '^':
            priority.append('4')
        elif i == '(':
            priority.append('1')
        elif i == ')':
            priority.append('-1')
 
        stack.append(i)                           # Помещаем символ операции в список stack
 
    if len(stack) > 1:                              # Сравниваем приоритеты символов операций и выбрасываем некоторые в список rpn
        for k in range(1, len(priority)):     
            if priority[-2] >= priority[-1]:
                rpn.append(stack.pop(-2))
                priority.pop(-2)
 
if len(stack) != 0:                                  # Если остались символы в стэке, то выбрасываем их в список rpn
    for i in range(len(stack))[::-1]:
        rpn.append(stack.pop(i))
        priority.pop(i)
 
print(''.join(rpn))   