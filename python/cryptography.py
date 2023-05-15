from Crypto.Random import get_random_bytes
from Crypto.Cipher import AES
import argparse


def create_key(size=16):
    key = get_random_bytes(size)
    file_out = open('key.key', 'wb')
    file_out.write(key)
    file_out.close()
    return key


def read_key(file):
    return open(f'{file}', 'rb').read()


def write_file(file, data):
    file_out = open(f'{file}', 'wb')
    file_out.write(data)
    file_out.close()


def read_file(file):
    return open(f'{file}', 'rb').read()


def write_data(name, cipher, tag, ciphertext):
    file_out = open(f'{name}', 'wb')
    [file_out.write(x) for x in (cipher.nonce, tag, ciphertext)]
    file_out.close()


def read_data(name):
    file_in = open(f'{name}', 'rb')
    return [file_in.read(x) for x in (16, 16, -1)]


def enc(input_file, key, output_file):
    cipher = AES.new(key, AES.MODE_EAX)
    data = read_file(input_file)
    ciphertext, tag = cipher.encrypt_and_digest(data)
    write_data(output_file, cipher, tag, ciphertext)


def dec(input_file, key, output_file):
    nonce, tag, ciphertext = read_data(input_file)
    cipher = AES.new(key, AES.MODE_EAX, nonce)
    text = cipher.decrypt_and_verify(ciphertext, tag)
    write_file(output_file, text)


def main():
    parser = argparse.ArgumentParser(description='Encrypt Files')
    parser.add_argument('-s', '--size',
                        type=int,
                        dest='size',
                        required=False,
                        help='size key')
    parser.add_argument('-i', '--input',
                        dest='input',
                        help='data input')
    parser.add_argument('-o', '--output',
                        dest='output',
                        help='data output')
    parser.add_argument('-k', '--key',
                        dest='key',
                        help='key')
    parser.add_argument('-e', '--encrypt',
                        action='store_true',
                        dest='encrypt',
                        help='encrypt')
    parser.add_argument('-d', '--decrypt',
                        action='store_true',
                        dest='decrypt',
                        help='decrypt')

    args = parser.parse_args()
    size = args.size
    input_file = args.input
    output_file = args.output

    try:
        key = read_key(args.key)
    except FileNotFoundError:
        key = create_key(size)

    if args.encrypt:
        enc(input_file, key, output_file)
    elif args.decrypt:
        dec(input_file, key, output_file)
    else:
        print('Error!')
        exit(0)


if __name__ == '__main__':
    main()
