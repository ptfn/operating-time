import requests
r = requests.get("https://api.bscscan.com/api?module=proxy&action=eth_getTransactionByHash&txHash=0x2c00e65221a2af9a60ed7d5b59bccaee422f056a48f2a37b841d0e042ba3cb9b")
data = r.json()
value = data["result"]["value"]
price = int(value, 16) / 10**18
print(price)