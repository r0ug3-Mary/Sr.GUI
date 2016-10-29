#include "inventorypage.h"
#include "ui_inventorypage.h"
#include "fak.h"
#include "dbmanager.h"

#include <QtDebug>
#include "QtDebug"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlTableModel>

//static const QString path = "/home/pi/Desktop/FAKKIT/db/fakdb4.db";

InventoryPage::InventoryPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InventoryPage)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:#626065;");

    QSqlQueryModel *modal =new QSqlQueryModel();
    DbManager db(path);
    QSqlQuery* query = new QSqlQuery();
    query->exec("SELECT * FROM Main");
    modal->setQuery(*query);
    ui->tableView->setModel(modal);
}

InventoryPage::~InventoryPage()
{
    delete ui;
}

void InventoryPage::on_HomeButton_clicked()
{
    close();
}

void InventoryPage::on_LowEmpButton_clicked()
{
    QSqlQueryModel *modal =new QSqlQueryModel();
    QSqlQuery* query = new QSqlQuery();
    query->exec("SELECT * FROM Main WHERE amount == 'Low' or amount == 'Empty'");
    modal->setQuery(*query);
    ui->tableView->setModel(modal);
}

void InventoryPage::on_RemoveButton_clicked()
{
    QSqlQueryModel *modal =new QSqlQueryModel();
    QSqlQuery* query = new QSqlQuery();

    int ID = ui->tableView->selectionModel()->currentIndex().row();
    qDebug() << ID;

    QString tablename = ui->tableView->model()->data(ui->tableView->model()->index(ID,1)).toString();
    qDebug() << tablename;

    query->prepare("DELETE FROM Main WHERE name = (:ref_name)");
    query->bindValue(":ref_name",tablename);
    query->exec();
    query->exec("SELECT * FROM Main");
    modal->setQuery(*query);
    ui->tableView->setModel(modal);
}

void InventoryPage::on_AllButton_clicked()
{
    QSqlQueryModel *modal =new QSqlQueryModel();
    QSqlQuery* query = new QSqlQuery();
    query->exec("SELECT * FROM Main");
    modal->setQuery(*query);
    ui->tableView->setModel(modal);
}

