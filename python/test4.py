f = open("file.txt", "r")

for i, name in enumerate(f.readlines()):
    print(f'''"{name[:50]}"''')
