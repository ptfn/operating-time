import requests
import sys

site = sys.argv[1]
site = "http://" + site

try:
  r = requests.get(site)
  if r.status_code in [200, 302, 304]:
    print ("Site working!")
  elif r.status_code in [502, 404, 403]:
    print ("Not Found")
  else: 
    print ("Unknown")

except:
  print ("Requests Error!")
