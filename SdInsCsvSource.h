#ifndef SDINSCSVSOURCE_H
#define SDINSCSVSOURCE_H
#include"InsSourceData.h"
#include<QTimer>
#include<QFile>
#include<QList>

class SdInsCsvSource: public InsSourceData
{
    Q_OBJECT
 public:

    SdInsCsvSource(QObject *parent=0);
    virtual void setUpdateInterval(int msec);
    virtual int minimumUpdateInterval() const;

public slots:
    virtual void startUpdates();
    virtual void stopUpdates();
    void readCSVfile();

//    virtual void requestUpdate(int timeout = 5000);

Q_SIGNALS:
    void stateUpdate(const stateVector &info);

private:
    QTimer *timer;
    QFile *csv_file;
    stateVector CSV_statevector;
    QList<stateVector> trajectory;
    int count;

};

#endif // SDINSCSVSOURCE_H
