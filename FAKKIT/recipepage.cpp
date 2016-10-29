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

//QString recId();

RecipePage::RecipePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecipePage)
{
    ui->setupUi(this);
    //lineEditkeyboard = new Keyboard();
    //connect(ui->lineEdit,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));

    this->setStyleSheet("background-color:#626065;");

    DbManager db(path);
    QSqlQueryModel *modal2 =new QSqlQueryModel();
    QSqlQuery* query = new QSqlQuery();
    QSqlQuery* query2 = new QSqlQuery();
    query->exec("SELECT * FROM codes");
    int idAmount = query->record().indexOf("");
    int idName = query->record().indexOf("name");
    query2->exec("SELECT name FROM codes");
    modal2->setQuery(*query2);
    ui->InventoryList->setModel(modal2);
    while(query->next())
        {
            QString name = query->value(idName).toString();
            QString amount = query->value(idAmount).toString();
            if(amount == "Empty")
                {
                    ui->RecipeParams->append(name);
                }
        }

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
    QSqlQueryModel *modal2 =new QSqlQueryModel();
    QSqlQuery* query2 = new QSqlQuery();
    QModelIndex index = ui->InventoryList->currentIndex();
    QString itemText = index.data(Qt::DisplayRole).toString();
    qDebug() << itemText;
    ui->RecipeParams->append(itemText);
    query2->exec("SELECT name FROM codes");
    modal2->setQuery(*query2);
    ui->InventoryList->setModel(modal2);
}

void RecipePage::on_SearchButton_clicked()
{
    //ui->RecipeParams->clear();
    //ui->listWidget->clear();
    QString params = ui->RecipeParams->toPlainText();

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

void RecipePage::url_links()
{
    QString linkss;
    QDesktopServices::openUrl(QUrl(linkss));
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

            QString links;
            links.at(ui->listWidget->addItem(obj["source_url"].toString());

            //connect(ui->listWidget, SIGNAL(doubleClicked(QListWidgetItem*)), this, SLOT(url_links()));

            //QString link = ui->listWidget->addItem(obj["source_url"].toString());
            //QDesktopServices::openUrl(QUrl(link));

            //connect(ui->listWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onHyperlinkActivated(QString)));
            //QDesktopServices::openUrl(ui->listWidget->addItem(obj["source_url"].toString()));

            //connect(ui->listWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onHyperlinkActivated(QString)));

            /*QItemSelectionModel *sm = ui->urlWidget->selectionModel();
            connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(onHyperlinkActivated(QString));*/

            //QDesktopServices::openUrl(links);

            //QLabel* hyperlinkWidget = new QLabel( QString("<span>%1&nbsp;&nbsp;</span><a href=\"%2\">%2</a>").arg(hyperlinkText), this);
            //setItemWidget(item, hyperlinkWidget);

            //QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
            //connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onHyperlinkActivated(QString&)));
            //ui->urlWidget->addItem(item);
        }

    }
    else {
        // an error occurred
        msg = "Error: " + worker->error_str;
    }
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

