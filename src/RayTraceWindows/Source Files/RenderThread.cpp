#include "RenderThread.h"
/******************************************************************************/
/********************* RenderPixel ********************************************/
/******************************************************************************/


RenderPixel::RenderPixel(int _x, int _y, int _red, int _green, int _blue)
	: x(_x), y(_y), red(_red), green(_green), blue(_blue)
{}



/******************************************************************************/
/********************* RenderThread *******************************************/
/******************************************************************************/


void RenderThread::setPixel(int x, int y, int red, int green, int blue)
{

	pixels.push_back(new RenderPixel(x, y, red, green, blue));

}

vector<RenderPixel*> * RenderThread::getPixel()
{
	//copy rendered pixels into a new vector and reset
	vector<RenderPixel*> *pixelsUpdate = new vector<RenderPixel*>(pixels);
//	pixels.clear();
	
	return pixelsUpdate;

}

void RenderThread::OnExit()
{

}

void *RenderThread::Entry()
{
	lastUpdateTime = 0;

	world->render_scene();

	return NULL;
}
