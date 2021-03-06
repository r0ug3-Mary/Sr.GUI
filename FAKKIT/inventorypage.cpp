﻿#include "inventorypage.h"
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

InventoryPage::InventoryPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InventoryPage)
{
    ui->setupUi(this);
    QDialog:showFullScreen();
    this->setStyleSheet("background-color:#626065;");
    ui->tableView->horizontalHeader()->setStyleSheet("color:black");
    ui->tableView->verticalHeader()->setStyleSheet("color:black");
    ui->tableView->setStyleSheet("background-color: #1c1b1b; font: bold 24px; color: white;");
    connect(ui->tableView->horizontalHeader(), SIGNAL(sectionResized(int,int,int)), ui->tableView, SLOT(resizeRowsToContents()));

    ui->AllButton->setStyleSheet("font: bold 32px; color: white;");
    ui->HomeButton->setStyleSheet("font: bold 32px; color: white;");
    ui->LowEmpButton->setStyleSheet("font: bold 32px; color: white;");
    ui->RemoveButton->setStyleSheet("font: bold 32px; color: white;");

    QSqlQueryModel *modal =new QSqlQueryModel();
    DbManager db(path);
    QSqlQuery* query = new QSqlQuery();
    query->exec("DELETE FROM Main WHERE rowid NOT IN (SELECT MAX(rowid) FROM Main GROUP BY Name)");
    query->exec("SELECT * FROM Main");
    modal->setQuery(*query);
    ui->tableView->setModel(modal);

    for (int c = 0; c < 2/*ui->tableView->horizontalHeader()->count()*/; ++c)
    {
        ui->tableView->horizontalHeader()->setSectionResizeMode(
            c, QHeaderView::Stretch);
        //ui->tableView->horizontalHeader()->resizeSection(2,20);
    }
    ui->tableView->horizontalHeader()->resizeSection(2,125);

    for (int c = 0; c < 2; ++c)
    {
        ui->tableView->horizontalHeader()->setSectionResizeMode(
            c, QHeaderView::Stretch);
    }
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
    query->exec("SELECT * FROM Main WHERE Amount == 'Low' or Amount == 'Empty'");
    modal->setQuery(*query);
    ui->tableView->setModel(modal);
}

void InventoryPage::on_RemoveButton_clicked()
{
    QSqlQueryModel *modal =new QSqlQueryModel();
    QSqlQuery* query = new QSqlQuery();

    int ID = ui->tableView->selectionModel()->currentIndex().row();
    qDebug() << ID;

    QString tablename = ui->tableView->model()->data(ui->tableView->model()->index(ID,0)).toString();
    qDebug() << tablename;

    query->prepare("DELETE FROM Main WHERE Name = (:ref_name)");

    query->bindValue(":ref_name", tablename);

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
