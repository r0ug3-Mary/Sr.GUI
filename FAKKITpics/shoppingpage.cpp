#include "shoppingpage.h"
#include "ui_shoppingpage.h"
#include "fak.h"

ShoppingPage::ShoppingPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShoppingPage)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:#626065;");
}

ShoppingPage::~ShoppingPage()
{
    delete ui;
}

void ShoppingPage::on_HomeButton3_clicked()
{

}

void ShoppingPage::on_AddButton_clicked()
{
    QListWidgetItem * item = new QListWidgetItem("New Item");
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    ui->ShoppingList->addItem(item);
}

void ShoppingPage::on_RemoveItem_clicked()
{
    QList<QListWidgetItem*> items = ui->ShoppingList->selectedItems();
    foreach(QListWidgetItem * item, items)
    delete ui->ShoppingList->takeItem(ui->ShoppingList->row(item));
}

void ShoppingPage::on_SaveList_clicked()
{
    //ui->ShoppingList->setData(items);
}
