class Car:
    def __init__(self, name, color, speed):
        self._name = name
        self._color = color
        self._speed = speed

    @property
    def color(self):
        return self.__color

    @color.setter
    def color(self, color):
        if len(color) != 0:
            self._color = color

    def display_info(self):
        print(f"Name: {self._name}\nColor: {self._color}\nSpeed: {self._speed}\n")


if __name__ == "__main__":
    cars = [Car("Car1", "Red", 120),
            Car("Car2", "Blue", 155),
            Car("Car3", "Green", 130)]

    # cars[1].color = "Purple"

    for i, name in enumerate(cars):
        name.display_info()
