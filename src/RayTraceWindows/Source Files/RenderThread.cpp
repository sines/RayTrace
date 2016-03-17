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

RenderThread::RenderThread(World* w) : world(w), terminate(false), width(0),
height(0), lastUpdateTime(0), pixelsRendered(0), pixelsToRender(0),pixmap(QPixmap(200, 200)), painter(&pixmap)
{
	pixels.clear();
}
//////////////////////////////////////////////////////////////////////////
// setPixel
void RenderThread::setPixel(int x, int y, int red, int green, int blue)
{
	if (pixelsToRender > pixelsRendered)
	{
		pixels.push_back(new RenderPixel(x, y, red, green, blue));
		NotifyCanvas();
		pixelsRendered++;
	}
	else
	{
		stop();
	}
}

//////////////////////////////////////////////////////////////////////////
//	GetPixel
vector<RenderPixel*> * RenderThread::getPixel()
{
	//copy rendered pixels into a new vector and reset
	vector<RenderPixel*> *pixelsUpdate = new vector<RenderPixel*>(pixels);
	return pixelsUpdate;
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
	width = world->vp.vres;
	height = world->vp.hres;
	world->render_scene();
	return NULL;
}


void RenderThread::run()
{
	if (false == terminate)
	{
		Entry();

		QFont f = painter.font();
		f.setPixelSize(20);
		painter.setFont(f);
		painter.setPen(Qt::black);
		painter.drawText(QRectF(0, 0, width, height), Qt::AlignCenter, "complete");
	}	
}

void RenderThread::stop()
{
	terminate = true;

}