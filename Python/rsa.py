import random

p = 3557  # random.randrange(1000,1000000)
q = 2579  # random.randrange(1000,1000000)

print("p =",p)
print("q =",q)

n = p * q
print("n =",n)
n1 = (p - 1) * (q - 1)
print("n1 =",n1)
e = 3 #random.randrange(2,1000)
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
  c = (m ** e) %  n 
  print ("c =",c)

if (menu == "d"):
  c = int(input("c ="))
  m = (c ** d) % n
  print ("m =",m)