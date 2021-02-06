#ifndef INSSOURCEDATA_H
#define INSSOURCEDATA_H

#include <QtCore/QObject>

struct stateVector
{
    float time;
    double latitude;
    double longitude;
    double altitude;
    float roll;
    float pitch;
    float head;

    stateVector():time(0.0), latitude(0.0),longitude(0.0),altitude(0.0),roll(0.0),pitch(0.0),head(0.0){}
};

class InsSourceData: public QObject
{
    Q_OBJECT

    Q_PROPERTY(int updateInterval READ updateInterval WRITE setUpdateInterval)
    Q_PROPERTY(int minimumUpdateInterval READ minimumUpdateInterval)

public:
    explicit InsSourceData(QObject *parent);
//    virtual ~InsSourceData();

    virtual void setUpdateInterval(int msec);
    int updateInterval() const
    {
        return m_updateInterval;
    }

    virtual int minimumUpdateInterval() const = 0;

public Q_SLOTS:
    virtual void startUpdates() = 0;
    virtual void stopUpdates() = 0;

//    virtual void requestUpdate(int timeout = 0) = 0;

Q_SIGNALS:
    void stateUpdate(const stateVector &info);
//    void updateTimeout();

protected:
    int m_updateInterval;
};
#endif // INSSOURCEDATA_H
