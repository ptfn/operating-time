from math import sqrt


class Vector:
    def __init__(self, x: float = 0, y: float = 0, z: float = 0):
        self.x = x
        self.y = y
        self.z = z

    def vector_length(self):
        return sqrt(self.x**2 + self.y**2 + self.z**2)


if __name__ == "__main__":
    v1 = Vector(2.1, 3, 4.14)
    print(v1.vector_length())
