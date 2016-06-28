#include "inisettings.h"

IniSettings::IniSettings(QObject *_parent) : QObject(_parent)
{
}

void IniSettings::init(const QString &_path)
{
    m_path = _path;
}

QMap<QString, QVariant> IniSettings::loadGroup(const QString &_group)
{
    QMap<QString, QVariant> data;
    QSettings settings(m_path, QSettings::IniFormat);
    settings.beginGroup(_group);
    const QStringList childKeys = settings.childKeys();
    foreach (const QString &childKey, childKeys)
        data.insert(childKey, settings.value(childKey));
    settings.endGroup();

    return data;
}

QVariant IniSettings::getValue(const QString &_group, const QString &_key)
{
    return loadGroup(_group).value(_key);
}

