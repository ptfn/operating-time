from tkinter import Tk, Canvas, Frame, BOTH
import random
import sys

class Point():
  def __init__(self, x, y, color):
    self.x = x
    self.y = y
    self.color = color

  def paint(self, canvas):
    canvas.create_rectangle(self.x, self.y, self.x + 1, self.y + 1, outline = self.color, width = 4)
 
class Example(Frame):
  
    def __init__(self, parent):
        Frame.__init__(self, parent , background = "black")   
        self.parent = parent        
        self.initUI()     
    
    def initUI(self):
        self.parent.title("Треугольник")        
        self.pack(fill=BOTH, expand=1)
        
        canvas = Canvas(self)
        canvas.pack(fill=BOTH, expand=1)

        a = Point(random.randrange(50, 300), random.randrange(50, 300), "green")
        a.paint(canvas)

        b = Point(random.randrange(50, 300), random.randrange(50, 300), "green")
        b.paint(canvas)

        c = Point(random.randrange(50, 300), random.randrange(50, 300), "green")
        c.paint(canvas)

        first = Point(random.randrange(50, 200), random.randrange(50, 2000), "red")
        first.paint(canvas)

        def calcPoint(p1:Point, p2:Point):
            if p1.x > p2.x: 
                x = ((p1.x - p2.x) / 2) + p2.x 
            else:
                x = ((p2.x - p1.x) / 2) + p1.x

            if p1.y > p2.y: 
                y = ((p1.y - p2.y) / 2) + p2.y
            else:
                y = ((p2.y - p1.y) / 2) + p1.y
            return Point(x,y,"blue")

        i = 0
        num = int(sys.argv[1]) # argument
        while i < num:
            random_dot = random.randrange(0,300)
          
            if random_dot > 0 & random_dot < 100:
                newp = calcPoint(p1 = a, p2 = first)
          
            if random_dot > 101 & random_dot < 200:
                newp = calcPoint(p1 = b, p2 = first)
            
            if random_dot > 201 & random_dot < 300:
                newp = calcPoint(p1 = c, p2 = first)

            newp.paint(canvas)
            first = newp
            i = i + 1
        
def main():
    root = Tk()
    _ex = Example(root)
    root.geometry("500x500")
    root.mainloop()  
 
if __name__ == '__main__':
    main()