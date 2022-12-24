inp = open("input.txt", "r")
out = open("output.txt", "w")

arr = inp.readlines()
string = arr[0]
string = string.replace(' ','')

arr2 = []
k = 0

for i in range(1,len(string)+1):
    if i % 8 == 0:
        arr2.append(string[k:i])
        k = i

for i in range(len(arr2)):
    arr2[i] = int('0x' + arr2[i],0)

string2 = str(hex(sum(arr2)))[2:]

if len(string2) != 0:
    l = 8 - len(string2)
    fst = ''
    for i in range(0,l):
        fst += '0'
    string2 = fst + string2

j = 0
arr3 = list(string2)

for i in range(1, len(arr3)+1):
    if i % 2 == 0:
        arr3[i-1] = arr3[i-1] + ' '

res = ''.join(arr3)
out.write("{}\n".format(res))
