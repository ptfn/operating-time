import requests
import time

wallet = input('Input wallet:')
balance = 0
start = 0

while True:
    r = requests.get('https://horizon.stellar.org/accounts/' + wallet)
    data = r.json()
    balance = data['balances'][0]['balance']

    if start != balance:
        print('The money has come!')
        start = balance
        
    print(balance)
    start = balance
    time.sleep(5)
