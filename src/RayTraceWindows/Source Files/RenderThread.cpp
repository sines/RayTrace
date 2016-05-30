#include "RenderThread.h"
#include "raytracewindows.h"

#include <QPainter>
#include <QImage>
/******************************************************************************/
/********************* RenderPixel ********************************************/
/******************************************************************************/
typedef pair<int, RenderPixel*> PixelPair;

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
	pixels_index.clear();
	pixelsToRender = world->vp.vres * world->vp.hres;
	width = world->vp.hres;
	height = world->vp.vres;
}
//////////////////////////////////////////////////////////////////////////
// setPixel
void RenderThread::SetPixel(int x, int y, int red, int green, int blue)
{
	if (pixelsToRender > pixelsRendered)
	{
		bool push = true;
		int index = x*width + y;

		std::map<int, RenderPixel*>::iterator result_it;
		result_it = pixels.find(index);
		if (result_it != pixels.end()) {

			float redf = (float)red / 255;
			float greenf = (float)green / 255;
			float bluef = (float)blue / 255;

			result_it->second->red = (1 - redf)*result_it->second->red + redf *redf* red;
			result_it->second->green = (1 - greenf)*result_it->second->green + greenf *greenf* green;
			result_it->second->blue = (1 - bluef)*result_it->second->blue + bluef *bluef* blue;

			push = false;
		}
		if (push)
		{
			
			pixels.insert(PixelPair(index,new RenderPixel(x, y, red, green, blue)));
			pixels_index.push_back(index);
		}

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
	pixels_index.clear();
	pixmap.fill(QColor(world->background_color.r * 255, world->background_color.g * 255, world->background_color.b * 255));
}
//////////////////////////////////////////////////////////////////////////
//	GetPixel
std::map<int, RenderPixel*>* RenderThread::GetPixel()
{
	//copy rendered pixels into a new vector and reset
	std::map<int, RenderPixel*>* pixelsUpdate = new std::map<int, RenderPixel*>(pixels);
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
	int index = pixels_index[pixelsRendered];
	RenderPixel* pixel = pixels[index];
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
	pixels_index.clear();

}

void *RenderThread::Entry()
{
	lastUpdateTime = 0;
	complete = false;

	//world->render_scene();
	world->get_camera()->render_scene(*world);
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

void
RenderThread::addlayer()
{
	pixelsRendered = 0;
};