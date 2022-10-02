from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *
import threading
import datetime
import schedule
import time
import csv
import sys


class Window(QWidget):
    def __init__(self, parent=None):
        super(Window, self).__init__(parent)
        # Windows
        self.resize(640, 480)
        self.setWindowTitle('Data Input')

        # Label
        self.label = QLabel(self)
        self.label.setGeometry(QRect(20, 30, 121, 41))
        font = QFont()
        font.setPointSize(18)
        self.label.setFont(font)
        self.label.setObjectName('label')

        # Label2
        self.label_2 = QLabel(self)
        self.label_2.setGeometry(QRect(200, 30, 281, 41))
        font = QFont()
        font.setPointSize(18)
        self.label_2.setFont(font)
        self.label_2.setObjectName('label_2')

        # Label3
        self.label_3 = QLabel(self)
        self.label_3.setGeometry(QRect(20, 100, 500, 50))
        font = QFont()
        font.setPointSize(18)
        self.label_3.setFont(font)
        self.label_3.setObjectName('label_2')

        # List
        self.list_1 = QListWidget(self)
        self.list_1.setGeometry(QRect(20, 150, 600, 320))
        font = QFont()
        font.setPointSize(18)
        self.list_1.setFont(font)
        self.list_1.setObjectName('list1')

        # Label Text
        self.label.setText('Date last: ')
        self.label_2.setText('None')

        self.csv_files()
        self.data_check()
        self.print_row(self.data)
        self.input_data()

    def run_func(self):
        schedule.every(1).seconds.do(self.csv_files)
        schedule.every(10).seconds.do(self.input_data())

        while True:
            schedule.run_pending()
            time.sleep(1)

    def csv_files(self):
        # CSV Files
        self.data = []
        csv_wfile = open('file.csv', 'a')
        csv_rfile = open('file.csv', 'r')

        self.csvwriter = csv.writer(csv_wfile)
        self.csvreader = csv.reader(csv_rfile)

        for row in self.csvreader:
            self.data.append(row)

        # csv_wfile.close()
        # csv_rfile.close()

    def data_check(self):
        # Filling out CSV files
        if self.data == []:
            self.csvwriter.writerow(['Date', 'Date Input', 'Sum'])
            self.label_2.setText('None')

    def input_data(self):
        csv_data = self.data
        try:
            date, num = self.inputdialog()

        except Exception:
            date, num = '0.0.0', 0

        finally:
            self.csvwriter.writerows([[self.get_date(), date, str(num)]])
            self.print_row(self.data)

            if len(csv_data) == 0 or len(csv_data) == 1:
                self.label_2.setText('None')

            else:
                self.label_2.setText(f"{csv_data[len(csv_data)-1][2]}")

    def get_date(self):
        today = datetime.date.today()
        return '{}.{}.{}'.format(today.day, today.month, today.year)

    def inputdialog(self):
        date, done1 = QInputDialog.getText(self, 'Input Date',
                                           'Enter the date (11.11.11):')
        num, done2 = QInputDialog.getInt(self, 'Input Num',
                                         'Enter the amount:')

        if done1 and done2:
            return date, num

    def print_row(self, data):
        string = ''
        self.list_1.clear()

        for i in range(len(data)):
            if i == 0:
                self.label_3.setText('{}\n'.format('\t'.join(data[i])))

            else:
                self.list_1.addItem('{}\n'.format('\t'.join(data[i])))


def main():
    app = QApplication(sys.argv)
    ex = Window()
    ex.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
