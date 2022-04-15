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
#include <QtWidgets/QHBoxLayout>
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
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonOpen;
    QPushButton *pushButtonBin;
    QPushButton *pushButtonText;
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
        result->setGeometry(QRect(50, 120, 91, 31));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(50, 150, 461, 351));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(50, 20, 461, 101));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonOpen = new QPushButton(horizontalLayoutWidget);
        pushButtonOpen->setObjectName(QString::fromUtf8("pushButtonOpen"));

        horizontalLayout->addWidget(pushButtonOpen);

        pushButtonBin = new QPushButton(horizontalLayoutWidget);
        pushButtonBin->setObjectName(QString::fromUtf8("pushButtonBin"));

        horizontalLayout->addWidget(pushButtonBin);

        pushButtonText = new QPushButton(horizontalLayoutWidget);
        pushButtonText->setObjectName(QString::fromUtf8("pushButtonText"));

        horizontalLayout->addWidget(pushButtonText);

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
        pushButtonOpen->setText(QApplication::translate("QtGuiFileTestClass", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        pushButtonBin->setText(QApplication::translate("QtGuiFileTestClass", "\344\272\214\350\277\233\345\210\266\346\226\207\344\273\266", nullptr));
        pushButtonText->setText(QApplication::translate("QtGuiFileTestClass", "\346\226\207\346\234\254\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiFileTestClass: public Ui_QtGuiFileTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIFILETEST_H
