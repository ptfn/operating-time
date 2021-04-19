import requests as rst

r = rst.get("https://mastodon.social/api/v1/timelines/public?remote=false&only_media=false")
data = r.json()
for i in data:
    print(i['content'])
