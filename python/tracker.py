from colorama import Fore, Style
import requests
import argparse
import time


def txt_yel(text):
    return Fore.YELLOW + text + Style.RESET_ALL


def pers(last, new):
    return round((new - last) / last * 100, 2)


def tracker(coin, wallet, money, limit):
    try:
        r = requests.get(f'https://api.bitfinex.com/v1/pubticker/{coin}{wallet}')
        data = r.json()
        price = data['ask']
        persent = pers(float(money), float(price))

        if persent >= float(limit):
            return txt_yel(f'--- LIMIT PRICE! ---') + f'\n{price}\t({persent} %)'
        else:
            return f'{price}\t{persent} %'

    except Exception:
        return 'Error request!'


def main():
    parser = argparse.ArgumentParser(description='Tracker Coin')
    parser.add_argument('-c', '--coin',
                        type=str,
                        dest='coin',
                        default='btc',
                        help='the coin you have chosen')
    parser.add_argument('-w', '--wallet',
                        type=str,
                        dest='wallet',
                        default='usd',
                        help='wallet coin')
    parser.add_argument('-m', '--money',
                        type=int,
                        dest='money',
                        default=10000,
                        help='number from which to track')
    parser.add_argument('-l', '--limit',
                        type=int,
                        dest='limit',
                        default=100,
                        help='limit track')
    parser.add_argument('-t', '--time',
                        type=int,
                        dest='time',
                        default=60,
                        help='second between request')

    args = parser.parse_args()

    coin = args.coin
    wallet = args.wallet
    money = args.money
    limit = args.limit
    stop = args.time

    while True:
        try:
            print(tracker(coin, wallet, money, limit))
            time.sleep(stop)

        except KeyboardInterrupt:
            print('Stop!')
            break


if __name__ == '__main__':
    main()
