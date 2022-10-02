import requests


def link_get(url):
    session = requests.session()
    session.proxies = {'http': 'socks5h://127.0.0.1:9150', 'https': 'socks5h://127.0.0.1:9150'}
    try:
        response = session.get(f"http://{url}")
        print(response)

    except Exception:
        print(1)

