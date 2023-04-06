from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP

key = RSA.generate(1024)
cipher_rsa = PKCS1_OAEP.new(key)

crypto = cipher_rsa.encrypt("Hello".encode())
print(crypto)

decrpyt = cipher_rsa.decrypt(crypto)
print(decrpyt)
