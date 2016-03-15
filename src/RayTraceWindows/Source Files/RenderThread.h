#ifndef _RENDERTHREAD_H_
#define _RENDERTHREAD_H_

#include "World.h"
#include <vector>

class RenderPixel
{
public:
	RenderPixel(int x, int y, int red, int green, int blue);

public:
	int x, y;
	int red, green, blue;
};


class RenderThread
{
public:
	RenderThread(World* w) : world(w){}
	virtual void *Entry();
	virtual void OnExit();
	virtual void setPixel(int x, int y, int red, int green, int blue);

	vector<RenderPixel*> * getPixel();

public:
	

	World* world;

	int width;
	int height;
	vector<RenderPixel*> pixels;
	long lastUpdateTime;
};
#endif