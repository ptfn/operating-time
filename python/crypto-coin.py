import os
import sys
import time
import requests
import argparse


def crypto_alert(currency, coins):
    string = '№\tName\tPrice\n'
    wallet = currency

    for i in range(len(coins)):
        try:
            coin = coins[i]

            if coin != wallet:
                r = requests.get(
                    f'https://api.bitfinex.com/v1/pubticker/{coin}{wallet}'
                )
                data = r.json()
                price = data['ask']
                string += f'{i+1}.\t{coin}\t{round(float(price), 2)}\n'

            else:
                string += f'{i+1}.\t{coin}\t1\n'

        except Exception:
            print('Error!')
            exit(0)

    return string


def main():
    parser = argparse.ArgumentParser(description='Crypto Alert')
    parser.add_argument('-c', '--currency',
                        type=str,
                        default='usd',
                        dest='currency',
                        help='currency for coin')
    parser.add_argument('-C', '--coin',
                        nargs='*',
                        default='btc',
                        dest='coin',
                        help='list coin')
    parser.add_argument('-t', '--time',
                        type=int,
                        default=60,
                        dest='time',
                        help='time clear')

    args = parser.parse_args()

    while True:
        try:
            os.system('clear')
            print(crypto_alert(args.currency, args.coin))
            time.sleep(args.time)

        except Exception:
            print('Error!')
            break

        except KeyboardInterrupt:
            break


if __name__ == '__main__':
    main()
