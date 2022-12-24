letters = "АОИЕЁЭЫУЮЯаоиеёэыуюя"


def text(text):
    l = [c for c in text if c in letters]
    print("Список гласных букв:", l)
    print(len(l))


if __name__ == "__main__":
    text(str(input("Введите текст ")))
