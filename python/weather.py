import requests


def get_weather(lat, lon, appid):
    try:
        q = requests.get(f"https://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&appid={appid}")
        data = q.json()

    except Exception as e:
        print(e)
    else:
        main = data["weather"][0]["description"]
        temp = data["main"]["temp"]
        humidity = data["main"]["humidity"]
        wind = data["wind"]["speed"]

        main = main.title()
        temp = str(round(temp - 273.15)) + '°C'
        wind = str(round(wind)) + ' m/s'
        humidity = str(humidity) + '%'

        return f"Main: {main}\nTemp: {temp}\nWind: {wind}\nHumidity: {humidity}"


if __name__ == "__main__":
    lat, lon, appid = 55, 82, "83bccb79b8413cf1a2ab73c10b27c682"
    print(get_weather(lat, lon, appid))
