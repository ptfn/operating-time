import sys

file_read = open(f"{sys.argv[1]}", "r")
file_write = open("file.txt", "w")
file_line = file_read.readlines()
arr = []

for i in range(len(file_line)):
    k = file_line[i].split()
    if k != []:
        if k[0] not in arr:
            arr.append(k[0])

arr.sort()

for i in range(len(arr)):
    file_write.write(f"{arr[i]}\n")
