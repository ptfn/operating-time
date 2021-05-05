import random

change = ['rock', 'paper', 'scissors']
cmp = 0
plr = 0

while 1:
    computer = random.choice(change)
    player = input('Your choice:')

    if computer == player:
        print('Computer choice:', computer)
        print('--Tie--')

    elif player == 'rock' or player == 'Rock':
        if computer == 'paper':
            print('Computer choice:', computer)
            print('--Lose--')
            cmp += 1
        else:
            print('Computer choice:', computer)
            print('--Win--')
            plr += 1

    elif player == 'paper' or player == 'Paper':
        if computer == 'scissors':
            print('Computer choice:', computer)
            print('--Lose--')
            cmp += 1
        else:
            print('Computer choice:', computer)
            print('--Win--')
            plr += 1

    elif player == 'scissors' or player == 'Scissors' :
        if computer == 'rock':
            print('Computer choice:', computer)
            print('--Lose--')
            cmp += 1
        else:
            print('Computer choice:', computer)
            print('--Win--')
            plr += 1

    elif player == 'result' or player == 'Result':
        print('* Computer:', cmp)
        print('* Player:', plr)

    elif player == 'final' or player == 'Final':
        print('* Computer:', cmp)
        print('* Player:', plr)
        break

    else:
        print('Enter your choice')
