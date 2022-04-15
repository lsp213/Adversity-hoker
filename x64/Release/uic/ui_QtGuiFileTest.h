/********************************************************************************
** Form generated from reading UI file 'QtGuiFileTest.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIFILETEST_H
#define UI_QTGUIFILETEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiFileTestClass
{
public:
    QWidget *centralWidget;
    QLabel *result;
    QTextBrowser *textBrowser;
    QPushButton *timeFre;
    QPushButton *addNoise;
    QPushButton *filtering;
    QPushButton *openFile;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiFileTestClass)
    {
        if (QtGuiFileTestClass->objectName().isEmpty())
            QtGuiFileTestClass->setObjectName(QString::fromUtf8("QtGuiFileTestClass"));
        QtGuiFileTestClass->resize(989, 654);
        centralWidget = new QWidget(QtGuiFileTestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        result = new QLabel(centralWidget);
        result->setObjectName(QString::fromUtf8("result"));
        result->setGeometry(QRect(20, 130, 91, 31));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 170, 461, 351));
        timeFre = new QPushButton(centralWidget);
        timeFre->setObjectName(QString::fromUtf8("timeFre"));
        timeFre->setGeometry(QRect(790, 20, 93, 28));
        addNoise = new QPushButton(centralWidget);
        addNoise->setObjectName(QString::fromUtf8("addNoise"));
        addNoise->setGeometry(QRect(530, 20, 93, 28));
        filtering = new QPushButton(centralWidget);
        filtering->setObjectName(QString::fromUtf8("filtering"));
        filtering->setGeometry(QRect(530, 70, 93, 28));
        openFile = new QPushButton(centralWidget);
        openFile->setObjectName(QString::fromUtf8("openFile"));
        openFile->setGeometry(QRect(40, 20, 93, 28));
        QtGuiFileTestClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiFileTestClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 989, 26));
        QtGuiFileTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiFileTestClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtGuiFileTestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiFileTestClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGuiFileTestClass->setStatusBar(statusBar);

        retranslateUi(QtGuiFileTestClass);

        QMetaObject::connectSlotsByName(QtGuiFileTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiFileTestClass)
    {
        QtGuiFileTestClass->setWindowTitle(QApplication::translate("QtGuiFileTestClass", "QtGuiFileTest", nullptr));
        result->setText(QApplication::translate("QtGuiFileTestClass", "\347\274\223\345\206\262\345\214\272", nullptr));
        timeFre->setText(QApplication::translate("QtGuiFileTestClass", "\346\227\266\351\242\221\345\210\207\346\215\242", nullptr));
        addNoise->setText(QApplication::translate("QtGuiFileTestClass", "\345\212\240\345\231\252", nullptr));
        filtering->setText(QApplication::translate("QtGuiFileTestClass", "\346\273\244\346\263\242", nullptr));
        openFile->setText(QApplication::translate("QtGuiFileTestClass", "\344\277\241\345\217\267\350\276\223\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiFileTestClass: public Ui_QtGuiFileTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIFILETEST_H
