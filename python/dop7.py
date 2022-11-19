def space(maxi, n):
    sp = ' '
    for i in range(maxi-n):
        sp += ' '
    return sp


def out(h, t, m):
    for i in range(len(h)):
        print(h[i], space(m[i], len(str(h[i]))), end='')
    print('\n')

    for i in range(len(t)):
        for j in range(len(t[0])):
            print(t[i][j], space(m[j], len(str(t[i][j]))), end='')
        print('')


def maxi(h, t):
    m = []

    for i in range(len(t[0])):
        m.append(0)

    for i in range(len(h)):
        m[i] = max(len(h[i]), m[i])

    for i in range(len(t)):
        for j in range(len(t[0])):
            m[j] = max(len(str(t[i][j])), m[j])

    return m


def main():
    header = ['name', 'kol', 'cont', 'bool', 'num']
    table = [
            ['lol', 2, 33.3, 'true', 1],
            ['lol', 2, 33.3, 'false', 2],
            ['name', 3, 56.5, 'false', 3],
            ['name2222', 4, 67.4, 'true', 3],
            ['name3', 4355, 3.141596, 'true', 4],
            ['nam', 4, 67.4, 'true', 5, 5]]

    maximus = maxi(header, table)
    out(header, table, maximus)


if __name__ == '__main__':
    main()
