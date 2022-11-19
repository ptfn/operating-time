from PIL import Image, ImageColor
from PIL import ImageDraw
import random
import sys


class Point():
    def __init__(self, x, y, color):
        self.x = x
        self.y = y
        self.color = color

    def paint(self, draw):
        draw.point((self.x, self.y), fill=ImageColor.getrgb(self.color))


class Triangle():
    def __init__(self, num: int):
        self.num = num
        self.width = 256
        self.height = 256
        self.colors = ["red", "blue", "green"]
        self.image = Image.new("RGB", (self.width, self.height))
        self.draw = ImageDraw.Draw(self.image)

    def rendering(self):
        p = Point(random.randint(0, self.height),
                  random.randint(0, self.width),
                  "blue")
        i = 0

        while i < self.num:
            p.paint(self.draw)
            p.x = random.randint(0, self.height)
            p.y = random.randint(0, self.width)
            p.color = random.choice(self.colors)

            i += 1

        self.image.save("save.png", "PNG")


def main():
    start = Triangle(int(sys.argv[1]))
    start.rendering()


if __name__ == '__main__':
    main()
