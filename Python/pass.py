
import hashlib
import base64

string = "123"
lenght = 20

hash = hashlib.sha256(str(string).encode("ascii")).hexdigest()
encbyte = base64.b64encode(hash.encode("utf-8"))
encstr = str(encbyte, "utf-8")

print("Password -> {}".format(encstr[:lenght]))
