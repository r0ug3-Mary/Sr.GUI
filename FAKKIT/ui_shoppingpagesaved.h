/********************************************************************************
** Form generated from reading UI file 'shoppingpagesaved.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPINGPAGESAVED_H
#define UI_SHOPPINGPAGESAVED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ShoppingPageSaved
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit;
    QPushButton *swapButton2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListView *listView;
    QLabel *label_2;
    QListView *listView_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *ShoppingPageSaved)
    {
        if (ShoppingPageSaved->objectName().isEmpty())
            ShoppingPageSaved->setObjectName(QStringLiteral("ShoppingPageSaved"));
        ShoppingPageSaved->resize(682, 641);
        gridLayout = new QGridLayout(ShoppingPageSaved);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textEdit = new QTextEdit(ShoppingPageSaved);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setStyleSheet(QLatin1String("background-color: #1c1b1b;\n"
"font: bold 12px; color: white;"));

        horizontalLayout_2->addWidget(textEdit);

        swapButton2 = new QPushButton(ShoppingPageSaved);
        swapButton2->setObjectName(QStringLiteral("swapButton2"));
        swapButton2->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(swapButton2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(ShoppingPageSaved);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("font: bold 14px;\n"
"    color: white;"));

        verticalLayout->addWidget(label);

        listView = new QListView(ShoppingPageSaved);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setStyleSheet(QLatin1String("background-color: #1c1b1b;\n"
"font: bold 12px; color: white;"));

        verticalLayout->addWidget(listView);

        label_2 = new QLabel(ShoppingPageSaved);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("font: bold 14px;\n"
"    color: white;"));

        verticalLayout->addWidget(label_2);

        listView_2 = new QListView(ShoppingPageSaved);
        listView_2->setObjectName(QStringLiteral("listView_2"));
        listView_2->setStyleSheet(QLatin1String("background-color: rgb(168, 165, 173);\n"
"font: bold 12px; color: white;"));

        verticalLayout->addWidget(listView_2);


        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(ShoppingPageSaved);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setStyleSheet(QLatin1String("background-color: rgb(168, 165, 173);\n"
"font: bold 12px; color: white;"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(ShoppingPageSaved);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("font: bold 14px;\n"
"    color: white;"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(ShoppingPageSaved);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QLatin1String("font: bold 14px;\n"
"    color: white;"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(ShoppingPageSaved);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setStyleSheet(QLatin1String("font: bold 14px;\n"
"    color: white;"));

        horizontalLayout->addWidget(pushButton_3);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(ShoppingPageSaved);
        QObject::connect(pushButton_3, SIGNAL(clicked()), ShoppingPageSaved, SLOT(reject()));

        QMetaObject::connectSlotsByName(ShoppingPageSaved);
    } // setupUi

    void retranslateUi(QDialog *ShoppingPageSaved)
    {
        ShoppingPageSaved->setWindowTitle(QApplication::translate("ShoppingPageSaved", "Dialog", 0));
        swapButton2->setText(QString());
        label->setText(QApplication::translate("ShoppingPageSaved", "Empty Items", 0));
        label_2->setText(QApplication::translate("ShoppingPageSaved", "Low on:", 0));
        pushButton->setText(QApplication::translate("ShoppingPageSaved", "Add", 0));
        pushButton_2->setText(QApplication::translate("ShoppingPageSaved", "Save", 0));
        pushButton_3->setText(QApplication::translate("ShoppingPageSaved", "Home", 0));
    } // retranslateUi

};

namespace Ui {
    class ShoppingPageSaved: public Ui_ShoppingPageSaved {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGPAGESAVED_H
