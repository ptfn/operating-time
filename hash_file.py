import hashlib

file_name = input('Имя файла:')
file = open(file_name, 'r')
string = file.readlines()
hash = ''

for i in range(len(string)):
    hash += string[i]

hash_md5 = hashlib.md5(str(hash).encode("ascii")).hexdigest()
hash_sha1 = hashlib.sha1(str(hash).encode("ascii")).hexdigest()
hash_sha256 = hashlib.sha256(str(hash).encode("ascii")).hexdigest()

print("md5:",hash_md5)
print("sha1:",hash_sha1)
print("sha256:",hash_sha256)