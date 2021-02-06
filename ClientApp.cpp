#include "ClientApp.h"
#include "SdInsCsvSource.h"

#include <QtCore>
#include<QDateTime>
#include<QString>
#include<QWidget>
#include<QTextEdit>

ClientApp::ClientApp(QWidget *parent):QMainWindow(parent)
{
    textEdit=new QTextEdit;
    setCentralWidget(textEdit);

    SdInsCsvSource *csv_app=new SdInsCsvSource(this);
     csv_app->startUpdates();
    connect(csv_app, SIGNAL(stateUpdate(stateVector)), this, SLOT(stateUpdate(stateVector)));
    connect(csv_app, &SdInsCsvSource::stateUpdate, this, &ClientApp::stateUpdate);



}

void ClientApp::stateUpdate(const stateVector &info)
{
    QString dt=QDateTime::currentDateTime().toString(Qt::ISODate);
     qDebug()<<info.head;
    textEdit->append(QString("%1, %2, %3, %4").arg(dt).arg(info.time).arg(info.latitude).arg(info.roll));
}
