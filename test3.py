import requests
r = requests.get('https://api.cryptonator.com/api/ticker/xmr-usd')

# data = r.json()
# price = data ['ticker']['price']
print(r.status_code)
