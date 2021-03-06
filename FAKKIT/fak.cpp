#include "fak.h"
#include "ui_fak.h"
#include "inventorypage.h"
#include "recipepage.h"
#include "viewpage.h"
#include "recentpage.h"
#include "QPixmap"
#include <QIcon>
#include "QPixmap"
#include "QSize"
#include "shoppingpage1.h"
#include "shoppingpagesaved.h"
#include "QtCore"
#include "QtGui"
#include "QMessageBox"

FAK::FAK(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FAK)
{
    ui->setupUi(this);
    //QMainWindow::showFullScreen();
    this->setStyleSheet("background-color:#626065;");

    //set button imgs and size
    ui->InventoryButton->setIcon(QIcon(":/pics/inventorybig.png"));
    ui->InventoryButton->setStyleSheet("background-color: #2e3192;");
    //ui->InventoryButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->InventoryButton->setIconSize(QSize(600,320));
    ui->RecipeButton->setIcon(QIcon(":/pics/recipebig.png"));
    ui->RecipeButton->setStyleSheet("background-color: #ffd204;");
    //ui->RecipeButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->RecipeButton->setIconSize(QSize(600,320));
    ui->ShoppingButton->setIcon(QIcon(":/pics/shoppingbig.png"));
    ui->ShoppingButton->setStyleSheet("background-color: #fcd711;");
    //ui->ShoppingButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->ShoppingButton->setIconSize(QSize(600,320));
    ui->pushButton->setIcon(QIcon(":/pics/picturebig.png"));
    ui->pushButton->setStyleSheet("background-color: #3e53a4;");
    //ui->pushButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->pushButton->setIconSize(QSize(600,320));
}

FAK::~FAK()
{
    delete ui;
}


void FAK::on_InventoryButton_clicked()
{
    InventoryPage inventoryPage;
    inventoryPage.exec();
}

void FAK::on_RecipeButton_clicked()
{
    RecipePage *recipePage=new RecipePage();
    recipePage->show();
}

void FAK::on_ShoppingButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Shopping List", "<font color = white >Do you wish to use the last saved shopping list?</font>",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        ShoppingPageSaved *shoppingPageSaved=new ShoppingPageSaved();
        shoppingPageSaved->show();
    }
    else if (reply == QMessageBox::No)
    {
        QMessageBox::StandardButton reply2;
        reply2 = QMessageBox::question(this, "New List", "<font color = white >If Yes is clicked, then the last saved Shopping List will be lost</font>",
                                       QMessageBox::Yes | QMessageBox::No);
                if (reply2 == QMessageBox::Yes)
                {
                    ShoppingPage1 *shoppingPage1=new ShoppingPage1();
                    shoppingPage1->show();
                }
                else if (reply2 == QMessageBox::No)
                {
                    delete ui;
                }
    }

}

void FAK::on_pushButton_clicked()
{
    ViewPage viewPage;
    viewPage.exec();
}
