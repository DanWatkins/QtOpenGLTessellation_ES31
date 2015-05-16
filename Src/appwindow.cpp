#include "appwindow.h"
#include "openglrenderitem.h"

#include <QtGui/QSurfaceFormat>

AppWindow::AppWindow()
{

}


void AppWindow::init()
{
	//configure qml stuff
	{
		qmlRegisterType<OpenGLRenderItem>("ES31_Test", 1, 0,
										  "OpenGLRenderer");

		QQuickView::setResizeMode(QQuickView::SizeRootObjectToView);
		QQuickView::setSource(QUrl(QStringLiteral("qrc:/Res/main.qml")));
	}

	//configure the surface format
	{
		QSurfaceFormat format = QWindow::format();
		format.setProfile(QSurfaceFormat::CoreProfile);

		#if defined(Q_OS_ANDROID)
			format.setRenderableType(QSurfaceFormat::OpenGLES);
			format.setVersion(3, 1);
		#else
			format.setRenderableType(QSurfaceFormat::OpenGL);
			format.setVersion(4, 1);
		#endif

		setFormat(format);
	}

	auto openglItem = rootObject()->findChild<OpenGLRenderItem*>("mainRenderable");
	QObject::connect(openglItem, &OpenGLRenderItem::readyToRender, []
	{
		qDebug() << "Ready to render, bitch";
	});
}
