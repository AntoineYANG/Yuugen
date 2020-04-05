/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QWidget *YBody;
    QVBoxLayout *verticalLayout;
    QWidget *YMenuBar;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QWidget *YContainer;
    QHBoxLayout *horizontalLayout_2;
    QWidget *YToolView;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;
    QScrollArea *YWorkspace;
    QWidget *YScrollArea;
    QHBoxLayout *horizontalLayout_4;
    QPlainTextEdit *YIndexView;
    QPlainTextEdit *YEditor;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(1140, 740);
        MainWindowClass->setMinimumSize(QSize(400, 500));
        MainWindowClass->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 27, 28);color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        verticalSpacer = new QSpacerItem(20, 36, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        YBody = new QWidget(centralWidget);
        YBody->setObjectName(QString::fromUtf8("YBody"));
        verticalLayout = new QVBoxLayout(YBody);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        YMenuBar = new QWidget(YBody);
        YMenuBar->setObjectName(QString::fromUtf8("YMenuBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(YMenuBar->sizePolicy().hasHeightForWidth());
        YMenuBar->setSizePolicy(sizePolicy1);
        YMenuBar->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 68, 72);"));
        horizontalLayout = new QHBoxLayout(YMenuBar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_2 = new QPushButton(YMenuBar);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(YMenuBar);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton = new QPushButton(YMenuBar);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addWidget(YMenuBar);

        YContainer = new QWidget(YBody);
        YContainer->setObjectName(QString::fromUtf8("YContainer"));
        YContainer->setStyleSheet(QString::fromUtf8("background-color: rgb(48, 48, 52);"));
        horizontalLayout_2 = new QHBoxLayout(YContainer);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        YToolView = new QWidget(YContainer);
        YToolView->setObjectName(QString::fromUtf8("YToolView"));
        YToolView->setStyleSheet(QString::fromUtf8("background-color: rgb(68,68,72);"));
        horizontalLayout_3 = new QHBoxLayout(YToolView);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_3 = new QPushButton(YToolView);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);


        horizontalLayout_2->addWidget(YToolView);

        YWorkspace = new QScrollArea(YContainer);
        YWorkspace->setObjectName(QString::fromUtf8("YWorkspace"));
        QFont font;
        font.setFamily(QString::fromUtf8("Operator Mono Bold"));
        font.setPointSize(11);
        YWorkspace->setFont(font);
        YWorkspace->setStyleSheet(QString::fromUtf8("background-color: rgb(68,68,72);"));
        YWorkspace->setWidgetResizable(true);
        YScrollArea = new QWidget();
        YScrollArea->setObjectName(QString::fromUtf8("YScrollArea"));
        YScrollArea->setGeometry(QRect(0, 0, 990, 619));
        horizontalLayout_4 = new QHBoxLayout(YScrollArea);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        YIndexView = new QPlainTextEdit(YScrollArea);
        YIndexView->setObjectName(QString::fromUtf8("YIndexView"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(YIndexView->sizePolicy().hasHeightForWidth());
        YIndexView->setSizePolicy(sizePolicy2);
        YIndexView->setMinimumSize(QSize(28, 0));
        YIndexView->setFont(font);

        horizontalLayout_4->addWidget(YIndexView);

        YEditor = new QPlainTextEdit(YScrollArea);
        YEditor->setObjectName(QString::fromUtf8("YEditor"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(YEditor->sizePolicy().hasHeightForWidth());
        YEditor->setSizePolicy(sizePolicy3);
        YEditor->setFont(font);

        horizontalLayout_4->addWidget(YEditor);

        YWorkspace->setWidget(YScrollArea);

        horizontalLayout_2->addWidget(YWorkspace);


        verticalLayout->addWidget(YContainer);


        verticalLayout_2->addWidget(YBody);

        MainWindowClass->setCentralWidget(centralWidget);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QCoreApplication::translate("MainWindowClass", "MainWindow", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindowClass", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindowClass", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindowClass", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindowClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
