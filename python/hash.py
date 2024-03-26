from hashlib import md5, sha1, sha256, sha512
from sys import argv

def main():
    choice = input("Select hash:\n* 1)MD5\n* 2)SHA1\n* 3)SHA256\n* 4)SHA512\n* 5)Exit\n:")
    text = argv[1]

    if choice == "1":
        res = md5(str(text).encode("ascii")).hexdigest()
        print("Hash -> {}".format(res))
    elif choice == "2":
        res = sha1(str(text).encode("ascii")).hexdigest()
        print("Hash -> {}".format(res))
    elif choice == "3":
        res = sha256(str(text).encode("ascii")).hexdigest()
        print("Hash -> {}".format(res))
    elif choice == "4":  
        res = sha512(str(text).encode("ascii")).hexdigest()
        print("Hash -> {}".format(res))
    elif choice == "5":
        exit(0)    
    else:
        print("Error choice!")
        exit(0)
    
if __name__ == "__main__":
    main()