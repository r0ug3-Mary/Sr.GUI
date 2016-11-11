#include "shoppingpage1.h"
#include "ui_shoppingpage1.h"
#include "fak.h"
#include "dbmanager.h"
#include <QtDebug>
#include "QtDebug"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QStringListModel>
#include <QFile>
#include <QTextStream>

ShoppingPage1::ShoppingPage1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShoppingPage1)
{
    ui->setupUi(this);
    lineEditkeyboard = new Keyboard();
    connect(ui->lineEdit,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));

    this->setStyleSheet("background-color:#626065;");

    DbManager db(path);
    QSqlQueryModel *modal2 =new QSqlQueryModel();
    QSqlQuery* query = new QSqlQuery();
    QSqlQuery* query2 = new QSqlQuery();
    query->exec("SELECT * FROM Main");
    int idAmount = query->record().indexOf("Amount");
    int idName = query->record().indexOf("Name");
    query2->exec("SELECT Name FROM Main WHERE Amount == 'Low'");
    modal2->setQuery(*query2);
    ui->listView_2->show(); //might need modal2 inside show
    while(query->next())
        {
            QString name = query->value(idName).toString();
            QString amount = query->value(idAmount).toString();
            if(amount == "Empty")
                {
                    ui->textEdit->append(name);
                }
        }
}

ShoppingPage1::~ShoppingPage1()
{
    delete ui;
}

void ShoppingPage1::run_keyboard_lineEdit()
{
    QLineEdit *line = (QLineEdit *)sender();
    lineEditkeyboard->setLineEdit(line);
    lineEditkeyboard->show();
}

void ShoppingPage1::on_swapButton_clicked()
{
    //SWAPPING
    QSqlQueryModel *modal2 =new QSqlQueryModel();
    QSqlQuery* query2 = new QSqlQuery();
    QModelIndex index = ui->listView_2->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    qDebug() << itemText;
    ui->textEdit->append(itemText);
    query2->exec("SELECT Name FROM Main WHERE Amount == 'Low'");
    modal2->setQuery(*query2);
    ui->listView_2->show();     //might need modal2 inside show

}

void ShoppingPage1::on_pushButton_3_clicked()
{
    //ADDING
    QString newItem = ui->lineEdit->text();
    ui->textEdit->append(newItem);
}

void ShoppingPage1::on_pushButton_2_clicked()
{
    //SAVING
    QString filename = "/home/r0ug3/Desktop/savelist.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        stream << ui->textEdit->toPlainText();
    }

}

