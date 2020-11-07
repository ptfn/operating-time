import random
Select = input("Шифровать(1) или Дешифровать(2):")
if Select == "1":
  #Данные и ключ
  print("---Шифрование---")
  text = input("Введите текст:")
  key = random.randrange(1024,4398046511104)
  print("Ключ:",key)
  #Шифрование
  def encrypt (text,key):
    encrypt_text = int(text) ^ int(key)
    return encrypt_text
  print("Зашифрованный текст:",encrypt(text,key))
elif Select == "2":
  #Данные и ключ
  print("---Дешифрование---")
  text = input("Введите зашифрованный текст:")
  key = input("Введите ключ:")
  #Дешифрование
  def dencrypt (text,key):
    dencrypt_text = int(text) ^ int(key)
    return dencrypt_text
  print("Текст:",dencrypt(text,key))