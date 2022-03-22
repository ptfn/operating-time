from ipfsApi import *
from sys import argv

api = Client('127.0.0.1', 5001)
file = input("File:")
res = api.add(f'{file}')
print('Name\t{}\nHash\t{}\nSize\t{} byte'.format(res['Name'], res['Hash'], res['Size']))
