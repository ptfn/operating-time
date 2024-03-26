from hashlib import md5, sha1, sha256
from os.path import getsize
from sys import argv

try:
    file_name =  argv[1]
except:
    print("Error argument!")
    exit(0)

file = open(file_name, 'r')
string = file.readlines()
hash = ''
folder_size = getsize(file_name)

for i in range(len(string)):
    hash += string[i]

hash_md5 = md5(str(hash).encode()).hexdigest()
hash_sha1 = sha1(str(hash).encode()).hexdigest()
hash_sha256 = sha256(str(hash).encode()).hexdigest()

print("Size\t{} Byte".format(folder_size))
print("MD5\t{}".format(hash_md5))
print("SHA1\t{}".format(hash_sha1))
print("SHA256\t{}".format(hash_sha256))
