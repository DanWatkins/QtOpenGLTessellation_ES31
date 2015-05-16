#include "TessellationRenderer.h"

TessellationRenderer::TessellationRenderer()
{

}


bool TessellationRenderer::init()
{
	initializeOpenGLFunctions();

	mIsInitialized = true;

	return true;
}


void TessellationRenderer::render()
{
	glClearColor(1.0f, 0.3f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
