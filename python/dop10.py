def sort_text(text):
    arr, text = list(text), ""
    for i in range(len(arr)):
        for j in range(len(arr)):
            if j != len(arr) - 1:
                if arr[j] > arr[j+1]:
                    arr[j], arr[j+1] = arr[j+1], arr[j]
    return text.join(arr)


if __name__ == "__main__":
    print(sort_text("Hello World!"))
