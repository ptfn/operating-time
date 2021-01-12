import random

change = ['rock', 'paper', 'scissors']
cmp = 0
plr = 0

while 1:
    computer = random.choice(change)
    player = input('Your choice:')

    if computer == player:
        print('Computer choice:', computer)
        print('Tie')

    elif player == 'rock':
        if computer == 'paper':
            print('Computer choice:', computer)
            print('Lose')
            cmp += 1
        else:
            print('Computer choice:', computer)
            print('Win')
            plr += 1

    elif player == 'paper':
        if computer == 'scissors':
            print('Computer choice:', computer)
            print('Lose')
            cmp += 1
        else:
            print('Computer choice:', computer)
            print('Win')
            plr += 1

    elif player == 'scissors':
        if computer == 'rock':
            print('Computer choice:', computer)
            print('Lose')
            cmp += 1
        else:
            print('Computer choice:', computer)
            print('Win')
            plr += 1

    elif player == 'result':
        print('Computer:', cmp)
        print('Player:', plr)

    elif player == 'final':
        print('Computer:', cmp)
        print('Player:', plr)
        break

    else:
        print('Enter your choice')
