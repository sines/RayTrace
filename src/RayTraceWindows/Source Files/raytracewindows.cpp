#include "raytracewindows.h"
#include <QFile>
#include <QMessageBox>
#include <QTextEdit>
#include <QTextStream>
#include <QFileDialog>
#include <QPainter>
#include <QImage>
RayTraceWindows::RayTraceWindows(QWidget *parent)
	: QMainWindow(parent), world(NULL), renderThread(NULL)
{
	ui.setupUi(this);
	ui.statusBar->showMessage(tr("Ready"));
	connect(ui.actionNew, SIGNAL(triggered()), this, SLOT(newFile()));
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
	connect(ui.actionAbout, SIGNAL(triggered()), this, SLOT(About()));
	connect(ui.actionStart, SIGNAL(triggered()), this, SLOT(startRender()));


/*
	// default
	QImage* img = new QImage;
	if (!img->load("../../../media/image/desktop.jpg")) //加载图像
	{
		QMessageBox::information(this,
			QString::fromLocal8Bit("打开图像失败"),
			QString::fromLocal8Bit("打开图像失败!"));
		delete img;
		return;
	}

	float oriwidth = img->width() / 2;
	float oriheight = img->height() / 2;
	QImage scaled_img = img->scaled(oriwidth, oriheight, Qt::IgnoreAspectRatio);
	ui.renderImage->setPixmap(QPixmap::fromImage(scaled_img));
*/
}


RayTraceWindows::~RayTraceWindows()
{

	if (world != NULL)
		delete world;

	if (renderThread != NULL)
		delete renderThread;
}
void RayTraceWindows::newFile()
{
	QString fileName = QFileDialog::getOpenFileName(this);
	if (!fileName.isEmpty())
		loadFile(fileName);
}

void RayTraceWindows::openFile()
{
	statusBar()->showMessage(tr("Open"), 2000);
}

void RayTraceWindows::startRender()
{
	world = new World;
	world->build();

	renderThread = new RenderThread(world);

	world->paintArea = renderThread;

	world->render_scene();

	//////////////////////////////////////////////////////////////////////////
	float vertexCount = renderThread->getPixel()->size();
	QImage* img = new QImage(200,200, QImage::Format_RGBA8888);
	int index = 0;
	
	//iterate over all pixels in the event
	vector<RenderPixel*> *pixelsUpdate = renderThread->getPixel();

	int width = img->width();
	int height = img->height();

	QPixmap pixmap(width, height);
	QPainter painter(&pixmap);
	for (vector<RenderPixel*>::iterator itr = pixelsUpdate->begin();
		itr != pixelsUpdate->end(); itr++)
	{
		RenderPixel* pixel = *itr;
		painter.setPen(QColor(pixel->red, pixel->green, pixel->blue));
		painter.drawPoint(pixel->x, pixel->y);
		delete pixel;
	}
	QFont f = painter.font();
	f.setPixelSize(20);
	painter.setFont(f);
	painter.setPen(Qt::black);
	painter.drawText(QRectF(0, 0, width, height), Qt::AlignCenter, "complete");
	ui.renderImage->setPixmap(pixmap);
	pixelsUpdate->clear();
	delete pixelsUpdate;

}

void RayTraceWindows::About()
{
	QMessageBox::about(this, tr("About Application"),
		QString::fromLocal8Bit("实现自<<射线跟踪算法>>系列书籍 "));
}
void RayTraceWindows::loadFile(const QString &fileName)
//! [42] //! [43]
{
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		QMessageBox::warning(this, tr("Application"),
			tr("Cannot read file %1:\n%2.")
			.arg(fileName)
			.arg(file.errorString()));
		return;
	}

	QTextStream in(&file);
#ifndef QT_NO_CURSOR
	QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
	textEdit->setPlainText(in.readAll());
#ifndef QT_NO_CURSOR
	QApplication::restoreOverrideCursor();
#endif

	statusBar()->showMessage(tr("File loaded"), 2000);
}