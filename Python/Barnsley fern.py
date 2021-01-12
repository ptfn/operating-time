from tkinter import Tk, Canvas, Frame, BOTH
import random


class Example(Frame):
    def __init__(self, parent):
        Frame.__init__(self, parent, background="black")
        self.parent = parent
        self.initUI()

    def initUI(self):
        self.parent.title("Барнсли папоротника")
        self.pack(fill=BOTH, expand=1)

        canvas = Canvas(self)
        canvas.pack(fill=BOTH, expand=1)

        x = 0.5
        y = 0.0
        i = 0

        for i in range(99999):
            r = random.uniform(0, 100)
            if r < 1.0:
                x = 0
                y = 0.16 * y
            elif r < 86.0:
                x = 0.85 * x + 0.04 * y
                y = -0.04 * x + 0.85 * y + 1.6
            elif r < 93.0:
                x = 0.2 * x - 0.26 * y
                y = 0.23 * x + 0.22 * y + 1.6
            else:
                x = -0.15 * x + 0.28 * y
                y = 0.26 * x + 0.24 * y + 0.44
            canvas.create_rectangle(
                66.0 * x + 300.0,
                66.0 * -y + 675.0,
                66.0 * x + 300.0,
                66.0 * -y + 675.0,
                outline = 'green',
                width = 0.00000001 )


def main():
    root = Tk()
    _ex = Example(root)
    root.geometry("900x900")
    root.mainloop()


if __name__ == '__main__':
    main()