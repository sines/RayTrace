#ifndef _RENDERTHREAD_H_
#define _RENDERTHREAD_H_

#include "World.h"
#include <vector>
#include <QtCore/QThread>
#include <QPixmap>
#include <QPainter>
class RenderPixel
{
public:
	RenderPixel(int x, int y, int red, int green, int blue);

public:
	int x, y;
	int red, green, blue;
};


class RenderThread : public QThread
{
public:
	RenderThread(World* w);
	virtual void *Entry();
	virtual void OnExit();
	virtual void setPixel(int x, int y, int red, int green, int blue);

	vector<RenderPixel*> * getPixel();
	void stop();

private:
	void NotifyCanvas();

public:
	virtual void run();

private:
	long pixelsRendered;
	long pixelsToRender;
	bool terminate;
public:
	
	World* world;

	int width;
	int height;
	vector<RenderPixel*> pixels;
	QPixmap pixmap;
	QPainter painter;
	long lastUpdateTime;
};
#endif