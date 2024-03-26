import random
import sys

def main():
    pn = gen_prime(1, 2**8)
    p = pn[random.randint(0, len(pn))]
    q = pn[random.randint(0, len(pn))]
    n = p * q
    fi = (p - 1) * (q - 1)
    e = pn[random.randint(0, len(pn))]
    d = dres(e, fi)
    print(f"p = {p}\nq = {q}\nn = {n}\nfi = {fi}\ne = {e}\nd = {d}")

    chc = sys.argv[1]
    msg = int(sys.argv[2])

    if  chc == "enc" or chc == "e":
        print(f"m = {msg}\nc = {enc(msg, e, n)}")
    
    elif chc == "dec" or chc == "d":
        print(f"c = {msg}\nm = {dec(msg, d, n)}")


def gen_prime(n, k):
    arr = [i for i in range(n, k)]
    arr2 = []

    for i in range(1, len(arr)):
        for j in range(1, len(arr)):
            res = i+j+2*i*j
            
            if res <= len(arr):
                arr[res-1] = 0

    for i in range(len(arr)):
        if arr [i] != 0:
            arr2.append(2*arr[i]+1)
  
    return arr2


def dres(e, el):
    for i in range(0,el):
        res = (e * i) % el
        
        if res == 1:
            return i    


def enc(m, e, n):
    return (m**e) % n


def dec(c, d, n):
    return (c**d) % n

if __name__ == "__main__":
    main()