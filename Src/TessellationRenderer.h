#ifndef TESSELLATIONRENDERER_H
#define TESSELLATIONRENDERER_H

#include "BaseOpenGLFunctions.h"

#include <QtGui/QOpenGLShaderProgram>

class TessellationRenderer : protected BaseOpenGLFunctions
{
public:
	TessellationRenderer();

	bool init();
	void render();

	bool isInitialized() { return mIsInitialized; }

private:
	bool mIsInitialized = false;
	QOpenGLShaderProgram mShaderProgram;
	GLuint mVao = -1;

	bool loadShaders();
};

#endif // TESSELLATIONRENDERER_H
