import requests
import time
crypto_wallet = input('Crypto_wallet:')
if crypto_wallet != '':
  wallet = input('Wallet:')
  if wallet != '':
    r = requests.get('https://api.cryptonator.com/api/ticker/' + crypto_wallet + "-" + wallet)
    data = r.json()
    price = data ['ticker']['price']
    change = data ['ticker']['change']
    while True:
      print(crypto_wallet,'=',price,wallet)
      print("change = ",change)
      if change <= '0':
        print('Not profitable to mine')
      time.sleep(120)
  else :
    print('error')
else :
  print("error")