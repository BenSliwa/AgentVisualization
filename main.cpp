#include <QGuiApplication>


#include "appcontroller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    AppController *controller = AppController::getInstance();



    return app.exec();
}
