import argparse
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

#KEY 
def create_key(size=16):
    key = get_random_bytes(size)
    file_out = open('key.key', 'wb')
    file_out.write(key)
    file_out.close()
    return key

def read_key():
    return open('key.key', 'rb').read()

#DATA
def write_file(file):
    return open(f'{file}', 'rb').write()

def read_file(file):
    return open(f'{file}', 'rb').read()

#CIPHER DATA
def write_data(name, cipher, tag, ciphertext):
    file_out = open(f'{name}.enc', 'wb')
    [file_out.write(x) for x in (cipher.nonce, tag, ciphertext) ]
    file_out.close()

def read_data(name):
    file_in = open(f'{name}.enc', 'rb')
    return [ file_in.read(x) for x in (16, 16, -1) ]

#CIPHER
def enc(data, key, name):
    cipher = AES.new(key, AES.MODE_EAX)
    ciphertext, tag = cipher.encrypt_and_digest(data)
    write_data(name, cipher, tag, ciphertext)

def dec(data, key):
    nonce, tag, ciphertext = read_data(data)
    cipher = AES.new(key, AES.MODE_EAX)
    cipher.decrypt_and_verify(ciphertext, tag)
    data = dec(ciphertext, tag, cipher)
    return data

def main():
    parser = argparse.ArgumentParser(description='Encrypt Files')
    parser.add_argument('-s', '--size', dest='size', help='size key')
    parser.add_argument('-i', '--input', dest='input', help='data input')
    parser.add_argument('-o', '--output', dest='output', help='data output')
    args = parser.parse_args()

    size = int(args.size)
    input_file = args.input

    key = create_key(size)
    data = read_file(input_file)
    
    enc(data, key, input_file)

if __name__ == '__main__':
    main()
