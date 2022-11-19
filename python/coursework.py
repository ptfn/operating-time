from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *
import datetime
import argparse
import notify2
import time
import csv
import sys


class Function(QWidget):
    def __init__(self, parent=None):
        super(Function, self).__init__(parent)
        self.data = []

    def csv_files(self, file_name='file.csv'):
        # CSV Files
        self.data = []
        csv_wfile = open(f'{file_name}', 'a')
        csv_rfile = open(f'{file_name}', 'r')

        self.csvwriter = csv.writer(csv_wfile)
        self.csvreader = csv.reader(csv_rfile)

        for row in self.csvreader:
            self.data.append(row)

    def data_check(self, label_2):
        # Filling out CSV files
        if self.data == []:
            self.csvwriter.writerow(['Date', 'Date Input', 'Sum'])
            label_2.setText('No')

    def input_data(self, file, label_2, label_3, list_1):
        try:
            date, num = self.inputdialog()

        except Exception:
            date, num = '00.00.00', 0

        finally:
            self.csvwriter.writerows([[self.get_date(), date, str(num)]])
            self.csv_files(file)
            self.print_row(self.data, label_3, list_1)

            if len(self.data) == 0 or len(self.data) == 1:
                label_2.setText('No')

            else:
                label_2.setText(f"{self.data[len(self.data)-1][2]}")

    def last_input_data(self, now, last):
        if int(now[3:5]) - int(last[3:5]) != 0:
            return True
        else:
            return False

    def get_date(self):
        today = datetime.datetime.now()
        return today.strftime('%X')

    def inputdialog(self):
        date, done1 = QInputDialog.getText(self, 'Input Date',
                                           'Enter the date (11.11.11):')
        num, done2 = QInputDialog.getInt(self, 'Input Num',
                                         'Enter the amount:')

        if done1 and done2:
            if len(date) >= 8:
                return date[:8], num

            else:
                return self.date_gen(date), num

    def date_gen(self, date):
        leng = 8 - len(date)
        for i in range(leng):
            if (i+leng) % 3 == 0:
                date += '.'

            else:
                date += '0'

        return date

    def print_row(self, data, label_3, list_1):
        string = ''
        list_1.clear()

        for i in range(len(data)):
            if i == 0:
                arr_str = '{} {} {}'.format(
                    data[i][0].ljust(22),
                    data[i][1].ljust(18),
                    data[i][2].ljust(10))
                label_3.setText('{}\n'.format(arr_str))

            else:
                arr_str = '{} {} {}'.format(
                    data[i][0].ljust(20),
                    data[i][1].ljust(22),
                    data[i][2].ljust(10))
                list_1.addItem('{}\n'.format(arr_str))

    def sum_data(self, label_5, data):
        sumn = 0
        for i in range(len(data)):
            if i != 0:
                sumn += int(data[i][2])

        label_5.setText(f"{sumn}")

    # def delitem(self, list_1):
    #     selected_row = list_1.currentRow()
    #     item = list_1.takeItem(selected_row)
    #     self.data.pop(selected_row)
    #     del item

    def notify(self, date):
        notify2.init("Input Data")
        n = notify2.Notification('You didn`t keep a date for the minutes')
        n.set_urgency(notify2.URGENCY_NORMAL)
        n.set_timeout(5000)

        while True:
            try:
                if self.last_input_data(self.get_date(),
                                        date[len(date)-1][0]):
                    n.show()
                    break

            except Exception:
                n.close()
                break


class Window(QWidget):
    def __init__(self, parent=None):
        super(Window, self).__init__(parent)
        self.func = Function()
        # Windows
        self.resize(960, 540)
        self.setWindowTitle('Data Input')

        # Label
        self.label = QLabel(self)
        self.label.setGeometry(QRect(700, 30, 140, 41))
        font = QFont()
        font.setBold(True)
        font.setPointSize(18)
        self.label.setFont(font)
        self.label.setObjectName('label')

        # Label2
        self.label_2 = QLabel(self)
        self.label_2.setGeometry(QRect(700, 80, 281, 41))
        font = QFont()
        font.setPointSize(18)
        self.label_2.setFont(font)
        self.label_2.setObjectName('label_2')

        # Label3
        self.label_3 = QLabel(self)
        self.label_3.setGeometry(QRect(20, 20, 700, 50))
        font = QFont()
        font.setBold(True)
        font.setPointSize(18)
        self.label_3.setFont(font)
        self.label_3.setObjectName('label_3')

        # Label4
        self.label_4 = QLabel(self)
        self.label_4.setGeometry(QRect(700, 130, 281, 41))
        font = QFont()
        font.setBold(True)
        font.setPointSize(18)
        self.label_4.setFont(font)
        self.label_4.setObjectName('label_4')

        # Label5
        self.label_5 = QLabel(self)
        self.label_5.setGeometry(QRect(700, 180, 281, 41))
        font = QFont()
        font.setPointSize(18)
        self.label_5.setFont(font)
        self.label_5.setObjectName('label_5')

        # List
        self.list_1 = QListWidget(self)
        self.list_1.setGeometry(QRect(20, 80, 650, 440))
        font = QFont()
        font.setPointSize(18)
        self.list_1.setFont(font)
        self.list_1.setObjectName('list_1')

        # Label Text
        self.label.setText('Last Input:')
        self.label_2.setText('No')
        self.label_4.setText('Sum: ')
        self.label_5.setText('No')

        # Button 1
        self.button_1 = QPushButton('Input', self)
        self.button_1.move(680, 480)
        self.button_1.resize(130, 40)
        self.button_1.clicked.connect(
            lambda: self.func.input_data(self.file_1[0],
                                         self.label_2,
                                         self.label_3,
                                         self.list_1))

        # Button 2
        self.button_2 = QPushButton('Sum', self)
        self.button_2.move(820, 480)
        self.button_2.resize(130, 40)
        self.button_2.clicked.connect(
            lambda: self.func.sum_data(self.label_5,
                                       self.func.data))

        # # Button 3
        # self.button_3 = QPushButton('Remove Item', self)
        # self.button_3.move(680, 430)
        # self.button_3.resize(270, 40)
        # self.button_3.clicked.connect(
        #     lambda: self.func.delitem(self.list_1))

    def graphics(self):
        # File Window
        self.file_1 = QFileDialog.getOpenFileName(self,
                                                  'Open file',
                                                  'home/ptfn/',
                                                  'CSV files (*.csv)')
        if self.file_1 == ('', ''):
            self.file_1 = 'file.csv', ''
            self.func.csv_files()
        else:
            self.func.csv_files(self.file_1[0])

        # Show Functions
        self.func.data_check(self.label_2)
        self.func.print_row(self.func.data, self.label_3, self.list_1)
        self.show()

    def notify_signal(self):
        self.func.csv_files()
        self.func.data_check(self.label_2)
        self.func.notify(self.func.data)


def main():
    app = QApplication(sys.argv)
    ex = Window()

    parser = argparse.ArgumentParser(description='Input Data')
    parser.add_argument('-g', '--graphics',
                        action='store_true',
                        dest='graphics',
                        help='graphics')
    parser.add_argument('-n', '--notify',
                        action='store_true',
                        dest='notify',
                        help='notify')

    args = parser.parse_args()

    if args.graphics:
        ex.graphics()
        sys.exit(app.exec_())

    elif args.notify:
        ex.notify_signal()

    else:
        print('Error!')
        exit(0)


if __name__ == '__main__':
    main()
