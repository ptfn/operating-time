import random

def StrToList(string):
    result = []
    for i in range(len(string)):
        result.append(ord(string[i]))
    return result


def ListToStr(arr):
    result = ""
    for i in range(len(arr)):
        result += chr(arr[i])
    return result


def GenKey(string):
    chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    key = ""
    for i in range(len(string)):
        key += random.choice(chars)
    return key


def Encrypt(string, key):
    key_num = StrToList(key)
    str_num = StrToList(string)
    enc = []
    for i in range(len(str_num)):
        enc.append(str_num[i] ^ key_num[i])
    res = ListToStr(enc)    
    return res


def Decrypt(string, key):
    str_num = StrToList(string)
    key_num = StrToList(key)
    dec = []
    for i in range(len(str_num)):
        dec.append(str_num[i] ^ key_num[i])
    res = ListToStr(dec)    
    return res


string = input("Text:")
choice = input("Encrypt or Decrypt:")

if choice == "Encrypt" or choice == "enc":
    key = GenKey(string)
    print("Key:",key)
    enc = Encrypt(string, key)
    print("Enc_Text:",enc)

elif choice == "Decrypt" or choice == 'dec':
    key = input("Key:")
    de = Decrypt(string, key)
    print("Dec_Text:",de)

else:
    print("Error")
