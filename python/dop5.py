txt = input()
rus, usa = False, False

for i in range(len(txt)):
    if ord(txt[i]) >= ord('A') and ord(txt[i]) <= ord('z'):
        usa = True

    elif ord(txt[i]) >= ord('А') and ord(txt[i]) <= ord('я'):
        rus = True

if rus and usa:
    print("Russian And English")

elif rus:
    print("Russian")

elif usa:
    print("English")

else:
    print("Not English And Russian")
