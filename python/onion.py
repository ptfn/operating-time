from numpy import random
import requests

chars = 'qwertyuiopasdfghjklzxcvbnm234567'


def link_get(url):
    session = requests.session()
    session.proxies = {'http': 'socks5h://127.0.0.1:9150',
                       'https': 'socks5h://127.0.0.1:9150'}
    try:
        response = session.get(f"http://{url}")
        return f"http://{url}"

    except Exception:
        return 'Error!'


def gen_onion():
    return ''.join([random.choice(list(chars)) for i in range(56)])


def main():
    while True:
        try:
            print(f"{link_get(gen_onion())}")

        except Exception:
            break


if __name__ == '__main__':
    main()
