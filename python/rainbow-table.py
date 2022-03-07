import hashlib

chars = "0123456789"
chars_len = len(chars)
pass_len = 8
chain_len = 10
chain_num = 1000000

def reduce(i):
    pwd = ""

    while len(pwd) < pass_len:
        pwd = pwd + chars[ i % chars_len ]
        i = i // chars_len
    return pwd

file = open("table.txt", 'a+', encoding='utf-8')

for s in range(0, chain_num):
    start = reduce(s)
    password = start

    for i in range(0, chain_len):
        hash_pass = hashlib.md5(password.encode('ascii')).hexdigest()
        password = reduce(int(hash_pass, 16))

    file.write('{}\n'.format(password))

file.close()