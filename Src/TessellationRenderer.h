#ifndef TESSELLATIONRENDERER_H
#define TESSELLATIONRENDERER_H

#include "BaseOpenGLFunctions.h"

class TessellationRenderer : protected BaseOpenGLFunctions
{
public:
	TessellationRenderer();

	bool init();
	void render();

	bool isInitialized() { return mIsInitialized; }

private:
	bool mIsInitialized = false;
};

#endif // TESSELLATIONRENDERER_H
