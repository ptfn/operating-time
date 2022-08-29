import sys
import random


def gen_num(number, n):
    for i in range(0, n):
        a = random.randint(1, len(number))
        number[str(a)] += 1


def main():
    n = int(sys.argv[1])
    dictionary = {str(x+1): 0 for x in range(6)}
    gen_num(dictionary, n)
    print("Число\tЧастота")
    for i in range(1, len(dictionary)+1):
        print(f"{i}\t{dictionary[str(i)]}")


if __name__ == "__main__":
    main()
