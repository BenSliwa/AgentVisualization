#include "filehandler.h"
#include <QFile>
#include <QTextStream>

FileHandler::FileHandler(QObject *_parent) : QObject(_parent)
{

}

QStringList FileHandler::readLines(const QString &_path)
{
    QStringList lines;
    QFile file(_path);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);

        while(!in.atEnd()) {
            QString line = in.readLine();
            lines << line;
        }

        file.close();
    }



    return lines;
}

