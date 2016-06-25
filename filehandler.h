#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QObject>
#include <QDebug>
#include <QStringList>

#include "Mobility/csvmobilitydataaccess.h"

class FileHandler : public QObject
{
    Q_OBJECT
public:
    FileHandler(QObject *_parent = 0);

    static QStringList readLines(const QString &_path);


};

#endif // FILEHANDLER_H
