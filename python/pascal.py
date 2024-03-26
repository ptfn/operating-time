from math import factorial as f

def combination_formula(n: int, k: int) -> int:
    return int(f(n) / (f(n-k) * f(k)))

def print_triagle(n: int, k: int):
    value = combination_formula(n, k)
    for i in range(2, n + 1):
        for j in range(1, i):
            now = combination_formula(i, j)
            if (value == now):
                print(f"[{now}]", end="\t")
            else:
                print(f"{now}", end="\t")
        print()

def main():
    print("Enter numbers:")
    n = int(input("n:"))
    k = int(input("k:"))

    print_triagle(n, k)

if __name__ == "__main__":
    main()

