TEMPLATE = app
QT += gui qml quick
CONFIG += c++14


RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Src/TessellationRenderer.h \
    Src/BaseOpenGLFunctions.h \
    Src/AppWindow.h \
    Src/OpenGLRenderItem.h

SOURCES += \
    Src/TessellationRenderer.cpp \
    Src/BaseOpenGLFunctions.cpp \
    Src/AppWindow.cpp \
    Src/Main.cpp \
    Src/OpenGLRenderItem.cpp

