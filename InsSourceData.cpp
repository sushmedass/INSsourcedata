#include "InsSourceData.h"

InsSourceData::InsSourceData(QObject *parent):QObject(parent)
{

}

void InsSourceData::setUpdateInterval(int msec)
{
 m_updateInterval=msec;
}
