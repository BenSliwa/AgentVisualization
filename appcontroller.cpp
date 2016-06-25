#include "appcontroller.h"
#include <QQmlContext>


AppController *appControllerInstance = 0;

AppController::AppController(QObject *_parent) : QObject(_parent)
{
    m_settings.init(":/Settings.ini");


    m_qml.load(QUrl(QStringLiteral("qrc:/main.qml")));
    m_qml.rootContext()->setContextProperty("AppController", this);

}

AppController* AppController::getInstance()
{
    if(!appControllerInstance)
        appControllerInstance = new AppController();

    return appControllerInstance;
}
