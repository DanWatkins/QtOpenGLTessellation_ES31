#include "openglrenderitem.h"
#include <QtQuick/QQuickWindow>

OpenGLRenderItem::OpenGLRenderItem()
{
	QObject::connect(this, SIGNAL(windowChanged(QQuickWindow*)),
					 this, SLOT(handleWindowChanged(QQuickWindow*)));
}


void OpenGLRenderItem::handleWindowChanged(QQuickWindow *window)
{
	if (window)
	{
		QObject::connect(window, SIGNAL(beforeSynchronizing()), this, SLOT(sync()), Qt::DirectConnection);
		QObject::connect(window, SIGNAL(sceneGraphInvalidated()), this, SLOT(cleanup()), Qt::DirectConnection);
		window->setClearBeforeRendering(false);
	}
}


void OpenGLRenderItem::sync()
{
	if (!mIsSynced)
	{
		QObject::connect(window(), SIGNAL(beforeRendering()),
							 this, SLOT(render()), Qt::DirectConnection);

		//TODO
		//QObject::connect(mCamera.get(), SIGNAL(finishedRendering()),
		//					this, SLOT(cameraFinishedRendering()), Qt::DirectConnection);

		mIsSynced = true;
	}
}


void OpenGLRenderItem::cameraFinishedRendering()
{
	window()->resetOpenGLState();
}


void OpenGLRenderItem::render()
{
	glClearColor(1.0f, 0.3f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	emit readyToRender();


	window()->update();
}