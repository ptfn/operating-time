cmd = "2234"
rbn = "1110001010001"

position = 0
cell = rbn[0]

for i in cmd:
    if cmd[i] == '1':
        position += 1
    elif cmd[i] == '2':
        position -= 1
    elif cmd[i] == '3':
        cell = rbn[position]
    elif cmd[i] == '4':
        if cell == '0':
            rbn[position] = '1'
        elif cell == '1':
            rbn[position] = '0'
        else:
            print('Error!')
    else:
        print('Error!')

print(rbn)