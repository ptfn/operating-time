def prime(n):
    for i in range(2, n):
        if (n % i == 0):
            return False
    return True


def generate_primes_arr(n):
    arr = []
    i = 2

    while n > 0:
        if prime(i):
            arr.append(i)
            n -= 1
        i += 1

    return arr


if __name__ == "__main__":
    print(generate_primes_arr(1000))
