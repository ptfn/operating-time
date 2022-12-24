Employee = [['John', '2332', 'j@mail.com'],
            ['Eva', '123652', 'eva@mail.com']]


class Employees:
    def __init__(self, db: list[list[str]]):
        self.name_db = db
        self.employee = None

    def find(self, find: str):
        for i in range(len(self.name_db)):
            if self.name_db[i][0] == find:
                self.employee = self.name_db[i]

                for i in range(3):
                    print(self.employee[i])


if __name__ == "__main__":
    e1 = Employees(Employee)
    e1.find("John")
