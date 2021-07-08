from sys import argv
import hashlib
import base64

string = argv[1]
lenght = 16

hash = hashlib.sha256(str(string).encode("ascii")).hexdigest()
encbyte = base64.b64encode(hash.encode("utf-8"))
encstr = str(encbyte, "utf-8")

print("Password -> {}".format(encstr[:lenght]))
