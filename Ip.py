import requests
site = input("Site(ya.ru):")
site = "http://" + site
try:
  r = requests.get(site)
  if r.status_code in [200, 302, 304]:
    print ("Site working!")
  elif r.status_code in [502, 404, 403]:
    print ("Not Found")
  else: 
    print ("Hz")
except:
  print ("requests error!")