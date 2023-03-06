from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
from PyQt5 import QtWidgets
import sys


class Ui_MainWindow(object):
    def __init__(self):
        #self.login = ["admin","test2"]
        #self.passw = ["123","000"]
        
        self.users = [{'login':'admin', 'pass':'123'},
                      {'login':'test2', 'pass':'000'}]

    def autorization(self):
        #self.lineEdit.setText(QCoreApplication.translate("MainWindow", u"test"))
        '''loginCur = self.lineEdit.text()
        passwCur = self.lineEdit_2.text()
        auto = False
        for i in range(len(self.login)):
            if(self.login[i] == loginCur and self.passw[i] == passwCur):
                auto = True
                break
        if auto == True:
            print('yes')
        else:
            print('no')'''
        loginCur = self.lineEdit.text()
        passwCur = self.lineEdit_2.text()
        auto = False
        for i in range(len(self.users)):
            if(self.users[i]['login'] == loginCur and self.users[i]['pass'] == passwCur):
                auto = True
                break
        if auto == True:
            print('yes')
        else:
            print('no')
        
    
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(373, 208)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.pushButton = QPushButton(self.centralwidget)
        self.pushButton.setObjectName(u"pushButton")
        self.pushButton.setGeometry(QRect(140, 110, 111, 21))
        self.pushButton.clicked.connect(self.autorization)
        
        font = QFont()
        font.setPointSize(11)
        self.pushButton.setFont(font)
        self.labelLogin = QLabel(self.centralwidget)
        self.labelLogin.setObjectName(u"labelLogin")
        self.labelLogin.setGeometry(QRect(45, 30, 91, 21))
        font1 = QFont()
        font1.setPointSize(14)
        self.labelLogin.setFont(font1)
        self.labelLogin.setLayoutDirection(Qt.LeftToRight)
        self.labelLogin.setAlignment(Qt.AlignRight|Qt.AlignTrailing|Qt.AlignVCenter)
        self.lineEdit = QLineEdit(self.centralwidget)
        self.lineEdit.setObjectName(u"lineEdit")
        self.lineEdit.setGeometry(QRect(140, 30, 113, 20))
        self.lineEdit.setFont(font)
        self.labelPass = QLabel(self.centralwidget)
        self.labelPass.setObjectName(u"labelPass")
        self.labelPass.setGeometry(QRect(50, 70, 91, 21))
        self.labelPass.setFont(font1)
        self.lineEdit_2 = QLineEdit(self.centralwidget)
        self.lineEdit_2.setObjectName(u"lineEdit_2")
        self.lineEdit_2.setGeometry(QRect(140, 70, 113, 20))
        self.lineEdit_2.setFont(font)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 373, 21))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.pushButton.setText(QCoreApplication.translate("MainWindow", u"Войти!", None))
        self.labelLogin.setText(QCoreApplication.translate("MainWindow", u"Login:", None))
        self.labelPass.setText(QCoreApplication.translate("MainWindow", u"Password:", None))
    # retranslateUi




if __name__ == "__main__":

    app = QtWidgets.QApplication(sys.argv)
    w = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(w)
    w.show()
    sys.exit(app.exec_())
