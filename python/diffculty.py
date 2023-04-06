import matplotlib.pyplot as plt
import requests

data = []

r = requests.get('https://localmonero.co/blocks/api/get_stats')
dr = r.json()
length = dr["height"]
print(length)

for i in range(1, 10):
    r = requests.get(f'https://localmonero.co/blocks/api/get_block_header/{i}')
    dr = r.json()
    data.append(dr["block_header"]["difficulty"])
    print(i)

plt.plot(data)
plt.show()
