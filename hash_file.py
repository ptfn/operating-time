import hashlib, os

file_name = input('Имя файла:')
file = open(file_name, 'r')
string = file.readlines()
hash = ''
folder_size = os.path.getsize(file_name)

for i in range(len(string)):
    hash += string[i]

hash_md5 = hashlib.md5(str(hash).encode()).hexdigest()
hash_sha1 = hashlib.sha1(str(hash).encode()).hexdigest()
hash_sha256 = hashlib.sha256(str(hash).encode()).hexdigest()

print("size: {} Byte".format(folder_size))
print("md5:",hash_md5)
print("sha1:",hash_sha1)
print("sha256:",hash_sha256)
