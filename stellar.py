import requests
import time
wallet = input('введите кошелёк ')
r = requests.get('https://horizon.stellar.org/accounts/' + wallet)
data = r.json()
balance = data['balances'][0]['balance']
balance1 = balance
while True:
    r = requests.get('https://horizon.stellar.org/accounts/' + wallet)
    data = r.json()
    balance = data['balances'][0]['balance']
    if balance1 != balance:
        print('опя мани пришли')
        balance1 = balance
    else:
        print(balance)
    time.sleep(10)