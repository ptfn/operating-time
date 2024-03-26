import sys
import requests

def main():
    appid = ""
    r = requests.get(f"https://api.openweathermap.org/geo/1.0/direct?q={sys.argv[1]}&limit=5&appid={appid}")
    data = r.json()
    lat = round(data[0]["lat"])
    lon = round(data[0]["lon"])

    q = requests.get(f"https://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lot}&appid={appid}")
    data = q.json()
    main = data["weather"][0]["description"]
    temp = data["main"]["temp"]
    humidity = data ["main"]["humidity"]
    wind = data["wind"]["speed"]

    main = main.title()
    temp = str(round(temp - 273.15)) + '°C'
    wind = str(round(wind)) + ' m/s'
    humidity = str(humidity) + '%'

    print(f"Weather:\nMain: {main}\nTemp: {temp}\nWind: {wind}\nHumidity: {humidity}")

if __name__ == "__main__":
    main()
