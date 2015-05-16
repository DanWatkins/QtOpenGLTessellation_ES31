TEMPLATE = app

QT += qml quick widgets
CONFIG += c++11


RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Src/appwindow.h \
    Src/openglrenderitem.h

SOURCES += \
    Src/appwindow.cpp \
    Src/main.cpp \
    Src/openglrenderitem.cpp
