#include "AppWindow.h"
#include "OpenGLRenderItem.h"

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
	QObject::connect(openglItem, &OpenGLRenderItem::readyToRender, [this]
	{
		if (mTessellationRenderer && mTessellationRenderer->isInitialized())
			mTessellationRenderer->render();
	});

	QObject::connect(this, &QQuickView::sceneGraphInitialized, [this]
	{
		qDebug() << "Initializing since screne graph is now ready";
		mTessellationRenderer = std::make_unique<TessellationRenderer>();
		mTessellationRenderer->init();
	});
}
