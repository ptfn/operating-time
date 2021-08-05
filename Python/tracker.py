import sys
import requests
import time

coin = "xmr"
wallet = "usd"
money = 200
time = 10


def pers(last, new):
    return round((new - last) / last * 100, 2)


while True:
    r = requests.get('https://api.bitfinex.com/v1/pubticker/'+ coin + wallet)
    data = r.json()
    price = data['ask']
    print("{} %".format(pers(float(money), float(price))))
    time.sleep(tiem)