#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QtQuick/QQuickView>

class AppWindow : public QQuickView
{
public:
	AppWindow();

	void init();
};

#endif // APPWINDOW_H
