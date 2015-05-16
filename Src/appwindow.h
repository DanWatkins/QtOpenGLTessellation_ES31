#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QtQuick/QQuickView>
#include <memory>
#include "TessellationRenderer.h"

class AppWindow : public QQuickView
{
public:
	AppWindow();

	void init();

private:
	std::unique_ptr<TessellationRenderer> mTessellationRenderer;
};

#endif // APPWINDOW_H
