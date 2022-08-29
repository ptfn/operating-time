import hashlib
import random
import base64
import sys


def password(string, lenght):
    for i in range(random.randint(2, 128)):
        string = hashlib.sha512(str(string).encode("ascii")).hexdigest()
    encbyte = base64.b64encode(string.encode("utf-8"))
    encstr = str(encbyte, "utf-8")[:lenght]
    return encstr


def main():
    string = sys.argv[1]
    lenght = int(sys.argv[2])
    print(f"Password -> {password(string, lenght)}")


if __name__ == "__main__":
    main()
