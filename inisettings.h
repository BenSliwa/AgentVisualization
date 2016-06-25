#ifndef INISETTINGS_H
#define INISETTINGS_H

#include <QObject>
#include <QDebug>
#include <QSettings>
#include <QMap>

class IniSettings : public QObject
{
    Q_OBJECT
public:
    IniSettings(QObject *_parent = 0);

    void init(const QString &_path);


    QMap<QString, QVariant> loadGroup(const QString &_group);
    QVariant getValue(const QString &_group, const QString &_key);

private:
    QString m_path;
};


#endif // INISETTINGS_H
