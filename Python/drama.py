inp = open("input.txt", "r")
out = open("output.txt", "w")

arr = [str(x) for x in inp.readlines()]
pos = arr.pop(0)

for i in range(len(arr)):
    arr[i] = arr[i].replace('\n','')
    arr[i] = arr[i].replace(' ',',')
    arr[i] = list(map(int, arr[i].split(',')))

for i in range(len(arr)):
    t1 = 0
    t2 = 0
    t3 = 0
    err = 0

    for k in range(1,len(arr[i])):
        try:
            if arr[i][k-1] == arr[i][k] and arr[i][k] < arr[i][k+1] and (k > 1 or k < len(arr[i])-1):
                if t1 == 0:
                    t1 = k
                else:
                    err = 1
            elif arr[i][k] < arr[i][k+1]:
                if t1 == 0:
                    t1 = k
            if arr[i][k-1] < arr[i][k] and arr[i][k] > arr[i][k+1] and (k > 1 or k < len(arr[i])-1):
                if t2 == 0:
                    t2 = k
                else:
                    err = 1
            if arr[i][k-1] > arr[i][k] and arr[i][k] == arr[i][k+1] and (k > 1 or len(arr[i])-1 < k):
                if t3 == 0:
                    t3 = k
                else:
                    err = 1
            elif arr[i][k] > arr[i][k+1] and len(arr[i])-1 == k+1:
                if t3 == 0:
                    t3 = k + 1
                else:
                    err = 1
        except:
            pass

    if t1 == 0 or t2 == 0 or t3 == 0 or err != 0:
        out.write("Nein\n")
    else:
        out.write("Freytag {} {} {}\n".format(t1,t2,t3))