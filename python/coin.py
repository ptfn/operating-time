import sys
import requests


def crypto_alert(wallet, coin):
    try:
        r = requests.get('https://api.bitfinex.com/v1/pubticker/' + coin + wallet)
        data = r.json()
        price = data['ask']
        return f"{round(float(price), 2)}"

    except Exception as e:
        print('Error!')
        exit(0)


def main():
    print(crypto_alert('usd', sys.argv[1]))


if __name__ == '__main__':
    main()
