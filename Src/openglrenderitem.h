#ifndef OPENGLRENDERITEM_H
#define OPENGLRENDERITEM_H

#include <QQuickItem>

class OpenGLRenderItem : public QQuickItem
{
	Q_OBJECT
public:
	OpenGLRenderItem();

private:
	bool mIsSynced = false;

signals:
	void readyToRender();

public slots:
	void sync();
	void cameraFinishedRendering();


private slots:
	void handleWindowChanged(QQuickWindow *window);
	void render();
};

#endif // OPENGLRENDERITEM_H
