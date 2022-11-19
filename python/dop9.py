def check_div(arr):
    max_div = 1

    for i in range(1, max(arr)):
        div = True

        for j in range(len(arr)):
            if arr[j] % i != 0:
                div = False

        if div:
            max_div = i

    return max_div


if __name__ == "__main__":
    print(check_div([2, 4, 6]))
    print(check_div([1, 3, 7]))
    print(check_div([32, 64, 128]))
