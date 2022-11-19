def sort_text(text):
    arr = list(text)
    for i in range(len(arr)):
        for j in range(len(arr)):
            if j != len(arr) - 1:
                if arr[j] > arr[j+1]:
                    arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr


if __name__ == "__main__":
    print(sort_text("Hello World!"))
