inp = open("input.txt", "r")
out = open("output.txt", "w")

low = 1
high = 10**6

while True:
    i = 1
    pos = inp.readline(i)
    mid = round((low + high) / 2)
    out.write("? {}\n".format(mid))

    if pos == "<":
        high = mid - 1
        continue
    
    elif pos == ">":
        low = mid + 1
        continue
    
    else:
        out.write("! {}\n".format(mid))
        break
    
    i += 1