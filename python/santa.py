import random


def gen_couple(arr1, arr2):
    a, b = None, None
    while True:
        a, b = random.choice(arr1), random.choice(arr2)
        if a != b:
            break
    return a, b


def santa(arr):
    arr1 = arr.copy()
    arr2 = arr.copy()
    result = []
    for i in range(len(arr)):
        a, b = gen_couple(arr1, arr2)
        arr1.remove(a)
        arr2.remove(b)
        result.append((a, b))
    return result


def main():
    friend = ["Егор", "Сонья", "Даня", "Родя", "Настя"]
    arr = santa(friend)
    for i, name in enumerate(arr):
        print(f"{i+1}. {name[0]} -> {name[1]}")


if __name__ == "__main__":
    main()
