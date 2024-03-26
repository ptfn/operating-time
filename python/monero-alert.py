import requests
import time
r = requests.get('https://api.cryptonator.com/api/ticker/xmr-usd')
q = requests.get('https://moneroblocks.info/api/get_stats')
s = requests.get('https://api.nanopool.org/v1/xmr/network/avgblocktime')
data = r.json()
data2 = q.json()
data3 = s.json()
data_time = data3['data']
difficulty = data2['difficulty']
hashrate = data2['hashrate']
height = data2['height']
price = data ['ticker']['price']
change = data ['ticker']['change']
while True:
    print('XMR =',price,"usd")
    print('Difficulty  = ',difficulty )
    print('Hashrate  = ', int(hashrate),"H/s")
    print('Height = ',height)
    print("Change = ",change)
    print('Average BLock Time = ',int(data_time))
    if change <= '0':
        print('Not profitable to mine')
    time.sleep(120)
