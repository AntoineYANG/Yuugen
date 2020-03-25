/********************************************************************************
** Form generated from reading UI file 'YTitleBar.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YTITLEBAR_H
#define UI_YTITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YTitleBar
{
public:
    QLabel *WindowIcon;

    void setupUi(QWidget *YTitleBar)
    {
        if (YTitleBar->objectName().isEmpty())
            YTitleBar->setObjectName(QString::fromUtf8("YTitleBar"));
        YTitleBar->resize(400, 36);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(YTitleBar->sizePolicy().hasHeightForWidth());
        YTitleBar->setSizePolicy(sizePolicy);
        YTitleBar->setStyleSheet(QString::fromUtf8("background-color: rgb(49, 49, 49);\n"
"color: rgb(254, 252, 242)"));
        WindowIcon = new QLabel(YTitleBar);
        WindowIcon->setObjectName(QString::fromUtf8("WindowIcon"));
        WindowIcon->setGeometry(QRect(4, 4, 28, 28));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(WindowIcon->sizePolicy().hasHeightForWidth());
        WindowIcon->setSizePolicy(sizePolicy1);
        WindowIcon->setPixmap(QPixmap(QString::fromUtf8("../public/icon0.png")));

        retranslateUi(YTitleBar);

        QMetaObject::connectSlotsByName(YTitleBar);
    } // setupUi

    void retranslateUi(QWidget *YTitleBar)
    {
        YTitleBar->setWindowTitle(QCoreApplication::translate("YTitleBar", "YTitleBar", nullptr));
        WindowIcon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class YTitleBar: public Ui_YTitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YTITLEBAR_H
