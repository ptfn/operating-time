ARR1 = [('A', 1), ('B', 1), ('C', 1)]
ARR2 = [('A', 21), ('B', 21)]
ARR3 = ['A', 'B', 'C', 'D', 'E', 'F']


def airplane(num):
    if num in [1, 2, 3]:
        return ARR1[num - 1]

    elif num in [118, 119]:
        return ARR2[num - 118]

    else:
        row, column = (num - 4) % 6, (num - 4) // 6 + 2
        row = ARR3[row]
        return row, column


def main():
    num = int(input())

    if 1 <= num <= 119:
        print(airplane(num))

    else:
        print('Error!')
        exit(0)


if __name__ == '__main__':
    main()
