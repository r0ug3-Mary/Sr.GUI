#include "recipepage.h"
#include "ui_recipepage.h"
#include "fak.h"
#include "inventorypage.h"
#include "dbmanager.h"
#include <QProcess>
#include <QTextStream>
#include <QtCore/QFile>
#include <QPushButton>
#include <QtDebug>
#include "QtDebug"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QProcess>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QLabel>
#include <QDesktopServices>
#include <QMessageBox>
#include <QListView>
#include <QListWidgetItem>
#include <QSqlQueryModel>
#include <QStringListModel>
#include <QStringList>
#include <QFile>
#include <QList>
#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QJsonArray>

RecipePage::RecipePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecipePage)
{
    ui->setupUi(this);
    QDialog::showMaximized();

    this->setStyleSheet("background-color:#626065;");
    ui->MoveOver->setStyleSheet("background-image: url(:/pics/next.png) 0 0 0 0 stretch stretch; background-position: center; background-repeat: repeat-false;");
        ui->MoveOver->setMinimumHeight(50);
        ui->MoveOver->setMinimumWidth(50);
        ui->InventoryList->setStyleSheet("background-color: #1c1b1b; font: bold 24px; color: white;");
        ui->InventoryList->setWordWrap(true);
        ui->InventoryList->setTextElideMode(Qt::ElideNone);
        ui->listWidget->setStyleSheet("background-color: #1c1b1b; font: bold 24px; color: white;");
        ui->listWidget->setWordWrap(true);
        ui->listWidget->setTextElideMode(Qt::ElideNone);
        ui->RecipeParams->setStyleSheet("background-color: #1c1b1b; font: bold 24px; color: white;");
        ui->HomeButton2->setStyleSheet("font: bold 32px; color: white;");
        ui->SearchButton->setStyleSheet("font: bold 32px; color: white;");
        ui->label->setStyleSheet("font: bold 24px; color: white;");
        ui->labelcurr->setStyleSheet("font: bold 24px; color: white;");
        ui->labellook->setStyleSheet("font: bold 24px; color: white;");
        ui->labelwht->setStyleSheet("font: bold 24px; color: white;");


    DbManager db(path);
    QSqlQueryModel *modal2 =new QSqlQueryModel();
    //QSqlQuery* query = new QSqlQuery();
    QSqlQuery* query2 = new QSqlQuery();
    //query->exec("SELECT * FROM Main");
    //int idAmount = query->record().indexOf("");
    //int idName = query->record().indexOf("Name");
    query2->exec("SELECT Name FROM Main");
    modal2->setQuery(*query2);
    ui->InventoryList->setModel(modal2);
    /*while(query->next())
        {
            QString name = query->value(idName).toString();
            QString amount = query->value(idAmount).toString();
            if(amount == "Empty")
                {
                    ui->RecipeParams->append(name);
                }
        }*/

}

RecipePage::~RecipePage()
{
    delete ui;
}

void RecipePage::run_keyboard_lineEdit()
{
    QLineEdit *line = (QLineEdit *)sender();
    lineEditkeyboard->setLineEdit(line);
    lineEditkeyboard->show();
}

void RecipePage::on_HomeButton2_clicked()
{
    close();
}

void RecipePage::on_MoveOver_clicked()
{
    //SWAPPING
    //QSqlQueryModel *modal2 =new QSqlQueryModel();
    //QSqlQuery* query2 = new QSqlQuery();
    QModelIndex index = ui->InventoryList->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    //qDebug() << itemText;
    //ui->RecipeParams->append(itemText);

    QSqlQuery* query1 = new QSqlQuery();
    query1->prepare("SELECT Category FROM Main WHERE Name = (:idname)");
    query1->bindValue(":idname", itemText);
    query1->exec();
    if (query1->next()) {
        QString stock = query1->value(0).toString();
            ui->RecipeParams->append(stock);
                qDebug() << stock;
        // You could store the information you obtain here in a vector or something
    }
    //ui->RecipeParams->append(stock);
    //qDebug() << stock;

    //query2->exec("SELECT Name FROM Main");
    //modal2->setQuery(*query2);
    //ui->InventoryList->setModel(modal2);
}

void RecipePage::on_SearchButton_clicked()
{
    //ui->RecipeParams->clear();
    //ui->listWidget->clear();
    QString params = ui->RecipeParams->toPlainText();
    params.replace("\n",",");
    params.replace(" ","%20");
    qDebug() << params;

    //call search api
    QString url1 = "http://food2fork.com/api/search?";
    url1.append("key=");
    url1.append("d6fd8f87abed004a5a382e1f2a9c30ae");
    url1.append("&q=");
    url1.append(params);

    //request from api
    HttpRequestInput input(url1, "GET");

    //input.add_var("", "");

    HttpRequestWorker *worker = new HttpRequestWorker(this);
    connect(worker, SIGNAL(on_execution_finished(HttpRequestWorker*)), this, SLOT(handle_result(HttpRequestWorker*)));
    worker->execute(&input);
}

QString fuckthisurl;
void RecipePage::fuckthislink()
{
    fuckthisurl = ui->listWidget->currentItem()->text();
    QDesktopServices::openUrl(QUrl(fuckthisurl));
    //qDebug() << ui->listWidget->currentItem()->text();
}

void RecipePage::handle_result(HttpRequestWorker *worker) {
    QString msg;

    if (worker->error_type == QNetworkReply::NoError) {
        // communication was successful
        msg = worker->response;

        //parse json array
        QJsonDocument document = QJsonDocument::fromJson(msg.toUtf8());
        QJsonObject object = document.object();
        QJsonValue value = object.value("recipes");
        QJsonArray array = value.toArray();

        //put array onto listWidget as titles
        foreach (const QJsonValue & value, array) {
            QJsonObject obj = value.toObject();
            ui->listWidget->addItem(obj["title"].toString());
            ui->listWidget->addItem(obj["source_url"].toString());
        }

    }
    else {
        // an error occurred
        msg = "Error: " + worker->error_str;
    }
connect(ui->listWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(fuckthislink()));
/*
    QMessageBox recmsg;
    recmsg.information(this, "", msg);
    recmsg.setDefaultButton(QMessageBox::Save);
*/
    /*
    //display on next page
    m_myProcess =  new QProcess();
    m_myProcess.setProcessChannelMode(QProcess::MergedChannels);
    */
}

/*
QProcess* RecipePage::getProcess()
{
   return  m_myProcess;
}
*/
