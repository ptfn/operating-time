import requests
import time
city = input("City:")
if city != "":
  r = requests.get('https://api.openweathermap.org/data/2.5/weather?q=' + city + '&APPID=4c49e2f94ec9e49b39574ed48a8f95ba')
  data = r.json()
  temp = data['main']['temp']
  cloud = data['weather'][0]['main']
  humidity = data['main']['humidity']
  wind = data ['wind']['speed']
  tempC = str(round(temp - 273.15)) + 'C'
  wind = str(round(wind)) + ' m/s'
  humidity = str(humidity) + '%'
  while True:
    print(city,':',tempC,'|',cloud,'|', humidity,'|',wind)
    time.sleep(120)
else:
  print("Error!")