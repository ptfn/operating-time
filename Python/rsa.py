import random
size_key1 =random.randrange(5,20)
size_key2 =random.randrange(5,20)
p = 2 ** size_key1
q = 2 ** size_key2
print("p =",p)
print("q =",q)
n = p * q
print("n =",n)
n1 = (p - 1) * (q - 1)
print("n1 =",n1)
e = random.randrange(2,100)
print("e = ", e)
def dres(e, el):
  for i in range(0,el):
    res = (e * i) % el
    if res == 1:
      return i
d = dres(e, n1)
print("{e,n}", e,n)
print("{d,n}", d,n)
menu = input("Encryption(e) / Decryption(d):")
if (menu == "e"):
  m = int(input("m ="))
  c = m ** e %  n 
  print ("c =",c)
if (menu == "d"):
  c = int(input("c ="))
  m = c ** d % n
  print ("m =",m)