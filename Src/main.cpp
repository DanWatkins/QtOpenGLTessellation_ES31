#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>

#include "appwindow.h"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	AppWindow appWindow;
	appWindow.init();
	appWindow.show();

    return app.exec();
}
