/********************************************************************************
** Form generated from reading UI file 'recipepage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECIPEPAGE_H
#define UI_RECIPEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecipePage
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelcurr;
    QSpacerItem *horizontalSpacer;
    QLabel *labellook;
    QHBoxLayout *horizontalLayout;
    QListView *InventoryList;
    QPushButton *MoveOver;
    QTextEdit *RecipeParams;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_11;
    QLabel *labelwht;
    QPushButton *SearchButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *HomeButton2;

    void setupUi(QDialog *RecipePage)
    {
        if (RecipePage->objectName().isEmpty())
            RecipePage->setObjectName(QStringLiteral("RecipePage"));
        RecipePage->resize(456, 325);
        RecipePage->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(RecipePage);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 438, 268));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, -1, 0, -1);
        labelcurr = new QLabel(layoutWidget);
        labelcurr->setObjectName(QStringLiteral("labelcurr"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelcurr->sizePolicy().hasHeightForWidth());
        labelcurr->setSizePolicy(sizePolicy);
        labelcurr->setMaximumSize(QSize(16777215, 838607));
        labelcurr->setStyleSheet(QLatin1String("font: bold 12px;\n"
"    color: white;"));

        horizontalLayout_8->addWidget(labelcurr);

        horizontalSpacer = new QSpacerItem(75, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        labellook = new QLabel(layoutWidget);
        labellook->setObjectName(QStringLiteral("labellook"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labellook->sizePolicy().hasHeightForWidth());
        labellook->setSizePolicy(sizePolicy1);
        labellook->setStyleSheet(QLatin1String("font: bold 12px;\n"
"    color: white;"));

        horizontalLayout_8->addWidget(labellook);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        InventoryList = new QListView(layoutWidget);
        InventoryList->setObjectName(QStringLiteral("InventoryList"));

        horizontalLayout->addWidget(InventoryList);

        MoveOver = new QPushButton(layoutWidget);
        MoveOver->setObjectName(QStringLiteral("MoveOver"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(MoveOver->sizePolicy().hasHeightForWidth());
        MoveOver->setSizePolicy(sizePolicy2);
        MoveOver->setMaximumSize(QSize(25, 16777215));
        MoveOver->setStyleSheet(QLatin1String("font: bold 12px;\n"
"    color: white;"));

        horizontalLayout->addWidget(MoveOver);

        RecipeParams = new QTextEdit(layoutWidget);
        RecipeParams->setObjectName(QStringLiteral("RecipeParams"));

        horizontalLayout->addWidget(RecipeParams);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayoutWidget_2 = new QWidget(RecipePage);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 290, 431, 31));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        labelwht = new QLabel(horizontalLayoutWidget_2);
        labelwht->setObjectName(QStringLiteral("labelwht"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelwht->sizePolicy().hasHeightForWidth());
        labelwht->setSizePolicy(sizePolicy3);
        labelwht->setStyleSheet(QLatin1String("font: bold 12px;\n"
"    color: white;"));
        labelwht->setWordWrap(true);

        horizontalLayout_11->addWidget(labelwht);

        SearchButton = new QPushButton(horizontalLayoutWidget_2);
        SearchButton->setObjectName(QStringLiteral("SearchButton"));
        sizePolicy2.setHeightForWidth(SearchButton->sizePolicy().hasHeightForWidth());
        SearchButton->setSizePolicy(sizePolicy2);
        SearchButton->setStyleSheet(QLatin1String("font: bold 14px;\n"
"    color: white;"));

        horizontalLayout_11->addWidget(SearchButton);

        horizontalSpacer_2 = new QSpacerItem(38, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);

        HomeButton2 = new QPushButton(horizontalLayoutWidget_2);
        HomeButton2->setObjectName(QStringLiteral("HomeButton2"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(HomeButton2->sizePolicy().hasHeightForWidth());
        HomeButton2->setSizePolicy(sizePolicy4);
        HomeButton2->setLayoutDirection(Qt::RightToLeft);
        HomeButton2->setStyleSheet(QLatin1String("font: bold 14px;\n"
"    color: white;"));

        horizontalLayout_11->addWidget(HomeButton2);

        layoutWidget->raise();
        horizontalLayoutWidget_2->raise();
        SearchButton->raise();

        retranslateUi(RecipePage);
        QObject::connect(HomeButton2, SIGNAL(clicked()), RecipePage, SLOT(reject()));

        QMetaObject::connectSlotsByName(RecipePage);
    } // setupUi

    void retranslateUi(QDialog *RecipePage)
    {
        RecipePage->setWindowTitle(QApplication::translate("RecipePage", "Dialog", 0));
        labelcurr->setText(QApplication::translate("RecipePage", "Current Inventory", 0));
        labellook->setText(QApplication::translate("RecipePage", "Recipe Parameters", 0));
        MoveOver->setText(QApplication::translate("RecipePage", "=>", 0));
        labelwht->setText(QApplication::translate("RecipePage", "When done click the search button :", 0));
        SearchButton->setText(QApplication::translate("RecipePage", "Search", 0));
        HomeButton2->setText(QApplication::translate("RecipePage", "Home", 0));
    } // retranslateUi

};

namespace Ui {
    class RecipePage: public Ui_RecipePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECIPEPAGE_H
