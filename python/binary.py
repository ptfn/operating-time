inp = open("input.txt", "r")
out = open("output.txt", "w")

low = 1
high = (10**6) - 1

while True:
    i = 1
    pos = inp.readline(i)
    mid = round((low + high) / 2)
    out.write("? {}\n".format(mid))

    if pos == "=":
        out.write("! {}\n".format(mid))
        break

    if pos == "<":
        high = mid - 1

    if pos == ">":
        low = mid + 1
    
    i += 1