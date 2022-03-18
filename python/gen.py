import random
import hashlib

chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!?@#$%^&*=<>()[]/|,.+-_"

def gen_token(length):
    password = ""
    key = ""
    for i in range(length):
        key += random.choice(chars)
    password = hashlib.sha1(str(key).encode("ascii")).hexdigest()
    password = hashlib.sha1(str(password).encode("ascii")).hexdigest()
    return password

def main():
    token = gen_token(256)
    print(token) 

if __name__ == "__main__":
    main()