#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QtQuick/QQuickView>

#include "TessellationRenderer.h"

class AppWindow : public QQuickView
{
public:
	AppWindow();

	void init();

private:
	TessellationRenderer mTessellationRenderer;
};

#endif // APPWINDOW_H
