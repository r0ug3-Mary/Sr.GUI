#include "recipepage.h"
#include "ui_recipepage.h"
#include "fak.h"
#include "inventorypage.h"
#include "reciperesultspage.h"
#include <QProcess>
#include <QtCore/QTextstream>
#include <QtCore/QFile>
#include <QPushButton>
#include <QtDebug>
#include "QtDebug"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

static const QString path = "C:/Users/r0ug3_h@cK3r/Documents/GitHub/Sr.GUI/FAKKIT/db/fakdb4.db";

RecipePage::RecipePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecipePage)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:#626065;");

    DbManager db(path);
    qDebug() << "Stuff in db:";
    QSqlQuery query;
    query.exec("SELECT * FROM codes");
    int idName = query.record().indexOf("name");
    while (query.next())
        {
            QString name = query.value(idName).toString();
            qDebug() << "===" << name;
            //ui->dbOutput->setPlainText(name);
            ui->InventoryList->append(name);
        }

}

RecipePage::~RecipePage()
{
    delete ui;
}

void RecipePage::on_HomeButton2_clicked()
{

}

void RecipePage::on_SearchButton_clicked()
{
    RecipeResultsPage reciperesultsPage;
    reciperesultsPage.setModal(true);
    reciperesultsPage.exec();
}

void RecipePage::on_MoveOver_clicked()
{

}
