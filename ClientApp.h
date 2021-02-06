#ifndef CLIENTAPP_H
#define CLIENTAPP_H
#include "InsSourceData.h"
#include <QMainWindow>
#include<QWidget>
#include<QTextEdit>

class ClientApp: public QMainWindow
{
    Q_OBJECT
public:
    ClientApp(QWidget *parent=0);
private slots:
    void stateUpdate(const stateVector &info);
private:
    QTextEdit *textEdit;
};

#endif // CLIENTAPP_H
