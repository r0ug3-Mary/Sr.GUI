#include "shoppingpagesaved.h"
#include "ui_shoppingpagesaved.h"
#include "dbmanager.h"
#include "keyboard/keyboard.h"
#include "keyboard/ui_keyboard.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
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
#include <QtCore>

ShoppingPageSaved::ShoppingPageSaved(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShoppingPageSaved)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:#626065;");

    //keyboard upon lineedit
    lineEditkeyboard = new Keyboard();
    connect(ui->lineEdit ,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));

    getTextFile();
    DbManager db(path);
    QSqlQueryModel *modal2 =new QSqlQueryModel();
    QSqlQuery* query2 = new QSqlQuery();
    QSqlQueryModel *modal3 =new QSqlQueryModel();
    QSqlQuery* query3 = new QSqlQuery();
    query2->exec("SELECT name FROM Main WHERE amount == 'Empty'");
    modal2->setQuery(*query2);
    ui->listView->setModel(modal2);
    query3->exec("SELECT name FROM Main WHERE amount == 'Low'");
    modal3->setQuery(*query3);
    ui->listView_2->setModel(modal3);
}

ShoppingPageSaved::~ShoppingPageSaved()
{
    delete ui;
}

void ShoppingPageSaved::on_pushButton_clicked()
{
    //ADDING
    QString newItem2 = ui->lineEdit->text();
    ui->textEdit->append(newItem2);
}

void ShoppingPageSaved::on_pushButton_2_clicked()
{
    //SAVING
    QString filename = "/home/r0ug3/Desktop/savelist.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite))
    {
        QTextStream stream2(&file);
        stream2 << ui->textEdit->toPlainText();
    }

}

void ShoppingPageSaved::on_swapButton2_clicked()
{
    //SWAPPING
    QSqlQueryModel *modal2 =new QSqlQueryModel();
    QSqlQuery* query2 = new QSqlQuery();
    QSqlQueryModel *modal3 =new QSqlQueryModel();
    QSqlQuery* query3 = new QSqlQuery();
    QModelIndex index = ui->listView->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    qDebug() << itemText;
    QModelIndex index2 = ui->listView_2->currentIndex();
    QString itemText2 = index2.data(Qt::DisplayRole).toString();
    qDebug() << itemText2;
    ui->textEdit->append(itemText);
    ui->textEdit->append(itemText2);
    query2->exec("SELECT name FROM Main WHERE amount == 'Empty'");
    modal2->setQuery(*query2);
    ui->listView->setModel(modal2);
    query3->exec("SELECT name FROM Main WHERE amount == 'Low'");
    modal3->setQuery(*query3);
    ui->listView_2->setModel(modal3);
}

void ShoppingPageSaved::getTextFile()
{
    QFile myFile("/home/r0ug3/Desktop/savelist.txt");
    myFile.open(QIODevice::ReadOnly);
    QTextStream textStream(&myFile);
    QString line = textStream.readAll();
    myFile.close();
    ui->textEdit->setPlainText(line);
}

void ShoppingPageSaved::run_keyboard_lineEdit()
{
    QLineEdit *line = (QLineEdit *)sender();
    lineEditkeyboard->setLineEdit(line);
    lineEditkeyboard->show();
}

void ShoppingPageSaved::on_pushButton_3_clicked()
{
    close();
}
