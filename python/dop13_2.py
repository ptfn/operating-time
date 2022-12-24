import sqlite3


class Employees:
    def __init__(self, db: str = "employee.db"):
        self.name_db = db
        self.employee = None

    def find(self, find: str):
        try:
            sqlite_connection = sqlite3.connect(self.name_db)
            cursor = sqlite_connection.cursor()
            cursor.execute(f"SELECT * FROM Employees WHERE Name = '{find}';")
            self.employee = cursor.fetchall()

            for i in range(3):
                print(self.employee[0][i])

        except sqlite3.OperationalError as error:
            print(error)

        except Exception:
            print("Not Found!")

        finally:
            if (sqlite_connection):
                sqlite_connection.close()


if __name__ == "__main__":
    e1 = Employees()
    e1.find("Bob")
