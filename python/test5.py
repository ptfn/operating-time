import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from messenger import Ui_MainWindow


class ExampleApp(QtWidgets.QMainWindow, Ui_MainWindow):          # +  Ui_MainWindow
    def __init__(self):
        super().__init__()

        self.setupUi(self)
        self.pushButton.clicked.connect(self.on_button_click) 
        self.lineEdit.editingFinished.connect(self.on_button_click)    # <<---<       

    def on_button_click(self):
        message = self.lineEdit.text()                          
        self.lineEdit.clear()                                     # +++
        self.plainTextEdit.appendPlainText(message)            


if __name__=="__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = ExampleApp()
    window.show()
    app.exec_()