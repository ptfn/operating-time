import hashlib

chars = "abcdefghijklmnopqrstuvwxyz"
chars_len = len(chars)


def reduce(i):
    pwd = ""

    while len(pwd) < 8:
        pwd = pwd + chars[ i % chars_len ]
        i = i // chars_len
    return pwd

file = open("table.txt", 'a+', encoding='utf-8')

for s in range(0, 100):
    start = reduce(s)
    password = start

    for i in range(0, 10000):
        hash_pass = hashlib.md5(password.encode('ascii')).hexdigest()
        password = reduce(int(hash_pass, 16))

    file.write('{0} -> {1}\n'.format(start, password))

file.close()