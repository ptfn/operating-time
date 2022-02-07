import requests

img2 = 'https://danbooru.donmai.us/posts/5050546'
img = 'https://cdn.donmai.us/original/ba/55/__drawn_by_jellytits_7__ba55a8db76ac1ef39d0eb54d8f0dcfee.jpg'

p = requests.get(img2)
out = open("img.jpg", "wb")
out.write(p.content)
out.close()