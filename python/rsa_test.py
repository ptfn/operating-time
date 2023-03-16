import rsa

(pub_key, sec_key) = rsa.newkeys(512)
print(pub_key.save_pkcs1('PEM'))
# with open('pub.pem', 'wb') as p:
#     p.write(pub_key.save_pkcs1('PEM'))
# with open('sec.pem', 'wb') as p:
#     p.write(sec_key.save_pkcs1('PEM'))
# message = 'hello Bob!'.encode('utf8')
# crypto = rsa.encrypt(message, pub_key)
# decrypt = rsa.decrypt(crypto, priv_key)
# print(f"{crypto}\n{decrypt}\n{pub_key}")
