def ack(n, m):
    if n == 0:
        return m + 1
    elif m == 0:
        return ack(n-1, 1)
    else:
        return ack(n-1, ack(n, m-1))


if __name__ == "__main__":
    print(ack(1, 100))
