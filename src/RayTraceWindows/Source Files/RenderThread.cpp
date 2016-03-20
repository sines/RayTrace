#include "RenderThread.h"
#include "raytracewindows.h"

#include <QPainter>
#include <QImage>
/******************************************************************************/
/********************* RenderPixel ********************************************/
/******************************************************************************/


RenderPixel::RenderPixel(int _x, int _y, int _red, int _green, int _blue)
	: x(_x), y(_y), red(_red), green(_green), blue(_blue)
{}



/******************************************************************************/
/********************* RenderThread *******************************************/
/******************************************************************************/

RenderThread::RenderThread(World* w) : world(w), terminate(false), height(w->vp.vres),
width(w->vp.hres), lastUpdateTime(0), pixelsRendered(0), pixelsToRender(0), pixmap(QPixmap(width, height)), painter(&pixmap), complete(false)
{
	pixels.clear();
}
//////////////////////////////////////////////////////////////////////////
// setPixel
void RenderThread::SetPixel(int x, int y, int red, int green, int blue)
{
	if (pixelsToRender > pixelsRendered)
	{
		pixels.push_back(new RenderPixel(x, y, red, green, blue));
		NotifyCanvas();
		pixelsRendered++;
	}
	else
	{
		complete = true;
		stop();
	}
}
void RenderThread::ClearState()
{
	complete = false;
	terminate = false;
	pixelsRendered = 0;
	pixels.clear();
	pixmap.fill(QColor(world->background_color.r * 255, world->background_color.g * 255, world->background_color.b * 255));
}
//////////////////////////////////////////////////////////////////////////
//	GetPixel
vector<RenderPixel*> * RenderThread::GetPixel()
{
	//copy rendered pixels into a new vector and reset
	vector<RenderPixel*> *pixelsUpdate = new vector<RenderPixel*>(pixels);
	return pixelsUpdate;
}

//////////////////////////////////////////////////////////////////////////
// GetProcess
float RenderThread::GetProcess()
{
	return (float)pixelsRendered / (float)pixelsToRender;
}


//////////////////////////////////////////////////////////////////////////
//	NotifyCanvas
void RenderThread::NotifyCanvas()
{
	//iterate over all pixels in the event
	RenderPixel* pixel = pixels[pixels.size()-1];
	painter.setPen(QColor(pixel->red, pixel->green, pixel->blue));
	painter.drawPoint(pixel->x, pixel->y);
}

//////////////////////////////////////////////////////////////////////////
//	OnExit
void RenderThread::OnExit()
{
	if (world != NULL)
		delete world;

	terminate = false;
	complete = false;
	width = 0;
	height = 0;
	lastUpdateTime = 0;
	pixelsRendered = 0;
	pixelsToRender = 0;
	pixels.clear();

}

void *RenderThread::Entry()
{
	lastUpdateTime = 0;
	pixelsToRender = world->vp.vres * world->vp.hres;
	width = world->vp.hres;
	height = world->vp.vres;
	complete = false;
	world->render_scene();
	return NULL;
}


void RenderThread::run()
{
	if (false == terminate)
	{
		ClearState();
		Entry();
		QFont f = painter.font();
		f.setPixelSize(20);
		painter.setFont(f);
		painter.setPen(Qt::black);
	}
	terminate = false;
}

void RenderThread::start()
{
	terminate = false;
	__super::start();
}
void RenderThread::stop()
{
	terminate = true;
}