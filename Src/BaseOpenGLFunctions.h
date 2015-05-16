#ifndef BASEOPENGLFUNCTIONS_H
#define BASEOPENGLFUNCTIONS_H

#include <QObject>

#if defined(Q_OS_WIN)
	#include <QtGui/QOpenGLFunctions_4_1_Core>
	class BaseOpenGLFunctions : protected QOpenGLFunctions_4_1_Core
#elif defined(Q_OS_ANDROID)
	#include <QtGui/QOpenGLFunctions>
	class BaseOpenGLFunctions : protected QOpenGLFunctions
#elif defined(Q_OS_IOS)
	#error I don't have an iOS device with GLES 3.1 to test with! Go ahead and try it though.
#else
	#This platform is not officially supported.
#endif

{
public:
	BaseOpenGLFunctions();
};

#endif // BASEOPENGLFUNCTIONS_H
