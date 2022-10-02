import tkinter
import random

def start():
    root.after_idle(loop, 0)   

def swap():
    scramble['text'] = get_scramble()

def get_scramble():
    scramble_length = random.randint(20, 23)
    moves = ["R", "R'", "R2", "L", "L'", "L2", "U", "U'", "U2", "D", "D'", "D2", "F", "F'", "F2", "B", "B'", "B2"]
    scramble = ""
    for i in range(0, scramble_length):
        random_move = random.randint(0, len(moves) - 1)
        if i > 0:
            while moves[random_move][0] == prev_move[0]:
                random_move = random.randint(0, len(moves) - 1)
        scramble += " " + moves[random_move]
        prev_move = moves[random_move]
    return scramble.strip()

def format(t):
    global time
    milliseconds = int(t % 10)
    sec = (t - milliseconds) / 10
    minutes = int(sec // 60)
    seconds = int(sec % 60)
    if seconds >=10:
        if minutes >= 10:
            return str(minutes) + ':' + str(seconds) + ':0' +str(milliseconds)
        else:
            return '0' + str(minutes) + ':' + str(seconds) + ':0' +str(milliseconds)
    else:
        if minutes >= 10:
            return str(minutes) + ':0' + str(seconds) + ':0' +str(milliseconds)
        else:
            return '0' + str(minutes) + ':0' + str(seconds) + ':0' +str(milliseconds)

def loop(n):
    label['text'] = str(format(n))
    root.after(100, loop, n+1)

root = tkinter.Tk()
    
label = tkinter.Label(font=(None, 100))
label['text'] = '00:00:00'
label.pack()

scramble = tkinter.Label(font=(None, 30))
scramble['text'] = get_scramble()
scramble.pack()

button = tkinter.Button(root, text="SWAP", command=swap)
button.pack()

button2 = tkinter.Button(root, text="START", command=start)
button2.pack()

root.mainloop()
