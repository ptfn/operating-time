import keyboard

while True:
    if keyboard.is_pressed('q'):
        print('You Pressed A Key!')
        break
    else:
        print('false')