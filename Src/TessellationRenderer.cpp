#include "TessellationRenderer.h"

#include <QtCore/QUrl>

TessellationRenderer::TessellationRenderer()
{

}


bool TessellationRenderer::init()
{
	initializeOpenGLFunctions();

	if (!loadShaders())
		return false;

	glGenVertexArrays(1, &mVao);
	glBindVertexArray(mVao);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	mIsInitialized = true;
	return true;
}


void TessellationRenderer::render()
{
	qDebug() << "Start tessellation render";
	glClearColor(1.0f, 0.3f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	if (mShaderProgram.bind())
	{
		glBindVertexArray(mVao);
		{
			glDrawArrays(GL_PATCHES, 0, 3);
		}
		glBindVertexArray(0);
		mShaderProgram.release();
	}
	qDebug() << "End tessellation render";
}


bool TessellationRenderer::loadShaders()
{
	//vertex shader
	{
		qDebug() << "Super path is " << QUrl(QStringLiteral("qrc:/Res/test.vs.glsl")).toLocalFile();

		auto shader = new QOpenGLShader(QOpenGLShader::Vertex, &mShaderProgram);
		shader->compileSourceFile(QUrl(QStringLiteral("qrc:/Res/test.vs.glsl")).toLocalFile());
		mShaderProgram.addShader(shader);
	}

	//tessellation control shader
	{
		auto shader = new QOpenGLShader(QOpenGLShader::TessellationControl, &mShaderProgram);
		shader->compileSourceFile(QUrl(QStringLiteral("qrc:/Res/test.tcs.glsl")).toLocalFile());
		mShaderProgram.addShader(shader);
	}

	//tessellation evaluation shader
	{
		auto shader = new QOpenGLShader(QOpenGLShader::TessellationEvaluation, &mShaderProgram);
		shader->compileSourceFile(QUrl(QStringLiteral("qrc:/Res/test.tes.glsl")).toLocalFile());
		mShaderProgram.addShader(shader);
	}

	//fragment shader
	{
		auto shader = new QOpenGLShader(QOpenGLShader::Fragment, &mShaderProgram);
		shader->compileSourceFile(QUrl(QStringLiteral("qrc:/Res/test.fs.glsl")).toLocalFile());
		mShaderProgram.addShader(shader);
	}

	if (!mShaderProgram.link())
		return false;
}
