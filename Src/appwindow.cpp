#include "appwindow.h"

#include <QtGui/QSurfaceFormat>

AppWindow::AppWindow()
{

}


void AppWindow::init()
{
	QQuickView::setResizeMode(QQuickView::SizeRootObjectToView);
	QQuickView::setSource(QUrl(QStringLiteral("qrc:/Res/main.qml")));

	//configure the surface format
	{
		QSurfaceFormat format = QWindow::format();
		format.setProfile(QSurfaceFormat::CoreProfile);

		#if defined(Q_OS_ANDROID)
			format.setRenderableType(QSurfaceFormat::OpenGLES);
			format.setVersion(3, 0);
		#else
			format.setRenderableType(QSurfaceFormat::OpenGL);
			format.setVersion(4, 1);
		#endif

		setFormat(format);
	}
}
