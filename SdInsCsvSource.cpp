#include "SdInsCsvSource.h"
#include<QWidget>
#include<QTextStream>
#include<QObject>
#include<QtCore>
#include<QString>
#include<QByteArray>
#include<QString>
#include<QTimer>

SdInsCsvSource::SdInsCsvSource(QObject *parent):InsSourceData(parent)
{
     csv_file=new QFile("sample.csv");
    if(!csv_file-> open(QIODevice::ReadOnly|QIODevice::Text))
    {qDebug()<<"not opening";}

    timer=new QTimer();
    count=0;

     connect(timer, &QTimer::timeout, this, &SdInsCsvSource::readCSVfile);

    QTextStream stream(csv_file);
    QString line;
    stream.readLine(); //reads 1st line

    do{
        line=stream.readLine();
        QStringList sl=line.split(',');
        CSV_statevector.time=sl.at(0).toInt();
        CSV_statevector.latitude=sl.at(1).toDouble();
        CSV_statevector.longitude=sl.at(2).toDouble();
        CSV_statevector.altitude=sl.at(3).toDouble();
        CSV_statevector.roll=sl.at(4).toFloat();
        CSV_statevector.pitch=sl.at(5).toFloat();
        CSV_statevector.head=sl.at(6).toFloat();

       trajectory.push_back(CSV_statevector);

      }while(!stream.atEnd());

}

void SdInsCsvSource::setUpdateInterval(int msec)
{
    m_updateInterval=msec;

};

int SdInsCsvSource::minimumUpdateInterval() const
{
    return 100;
}

void SdInsCsvSource::startUpdates()
{
    int interval = updateInterval();
    if (interval < minimumUpdateInterval())
        interval = minimumUpdateInterval();

    timer->start(interval);
}

void SdInsCsvSource::stopUpdates()
{
    timer->stop();
}

void SdInsCsvSource::readCSVfile()
{
    if(++count==trajectory.size()) {count=0;}
    qDebug()<<trajectory.size();
    emit stateUpdate(trajectory.at(count));
}
