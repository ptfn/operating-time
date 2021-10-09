inp = open("input.txt", "r")
out = open("output.txt", "w")

arr = [float(x) for x in inp.readlines()]
a = arr[0]
b = arr[1]
c = arr[2]
D = (b**2) - (4 * a * c)

if D > 0:
    x1 = (-b-(D**0.5))/(2*a)
    x2 = (-b+(D**0.5))/(2*a)
    out.write("2\n{}\n{}".format(x1,x2))

elif D == 0:
    x = (-b)/(2*a)
    out.write("1\n{}".format(x))

elif D < 0:
    out.write("0")