TEMPLATE = app

QT += qml quick network
CONFIG += c++11

SOURCES += main.cpp \
    inisettings.cpp \
    appcontroller.cpp \
    filehandler.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    inisettings.h \
    appcontroller.h \
    filehandler.h


include(Agent/Agent.pri)
include(ChannelModel/ChannelModel.pri)
include(Mobility/Mobility.pri)
include(Net/Net.pri)
