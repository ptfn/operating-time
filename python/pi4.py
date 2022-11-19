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
        self.width = 2048
        self.height = 2048
        self.image = Image.new("RGB", (self.width, self.height))
        self.draw = ImageDraw.Draw(self.image)

    def rendering(self):
        p = Point(random.randint(0, self.height),
                  random.randint(0, self.width),
                  "blue")
        i, num_ing = 0, 0

        while i < self.num:
            if p.x**2 + p.y**2 <= self.width**2:
                p.paint(self.draw)
                num_ing += 1

            p.x = random.randint(0, self.height)
            p.y = random.randint(0, self.width)
            i += 1

        print((num_ing/self.num)*4)
        self.image.save("save.png", "PNG")


def main():
    start = Triangle(int(sys.argv[1]))
    start.rendering()


if __name__ == '__main__':
    main()
