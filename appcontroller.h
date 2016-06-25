#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QQmlApplicationEngine>

#include "inisettings.h"

class AppController : public QObject
{
    Q_OBJECT
public:
    AppController(QObject *_parent = 0);
    static AppController* getInstance();

private:
    QQmlApplicationEngine m_qml;

    IniSettings m_settings;
};

#endif // APPCONTROLLER_H
