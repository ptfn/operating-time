from PIL import Image, ImageColor
from PIL import ImageDraw
import random


class Point():
    def __init__(self, x, y, color):
        self.x = x
        self.y = y
        self.color = color

    def paint(self, draw):
        draw.point((self.x, self.y), fill=ImageColor.getrgb(self.color))


class Noise():
    def __init__(self):
        self.width = 256
        self.height = 256
        self.image = Image.new("RGB", (self.width, self.height))
        self.draw = ImageDraw.Draw(self.image)

    def rendering(self):
        p = Point(1, 1, "white")

        for x in range(self.width):
            for y in range(self.height):
                p.x, p.y = x, y
                if x&y:
                    p.color = "white"
                    p.paint(self.draw)
                else:
                    p.color = "black"
                    p.paint(self.draw)

        self.image.save("save.png", "PNG")


def main():
    start = Noise()
    start.rendering()


if __name__ == '__main__':
    main()
