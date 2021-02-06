#include <QApplication>
#include<QMainWindow>
#include "ClientApp.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ClientApp client;
    client.show();

    return app.exec();
}
