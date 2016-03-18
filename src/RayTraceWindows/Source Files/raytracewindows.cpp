#include "raytracewindows.h"
#include <QFile>
#include <QMessageBox>
#include <QTextEdit>
#include <QTextStream>
#include <QFileDialog>
#include <QPainter>
#include <QImage>
RayTraceWindows::RayTraceWindows(QWidget *parent)
	: QMainWindow(parent), world(NULL), renderThread(NULL), timerRender(0)
{
	ui.setupUi(this);
	ui.statusBar->showMessage(tr("Ready"));
	timerRender = new QTimer(this);
	timerRender->setObjectName(QString::fromUtf8("timer1s"));
	setFocusPolicy(Qt::NoFocus);
	connect(ui.actionNew, SIGNAL(triggered()), this, SLOT(newFile()));
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
	connect(ui.actionAbout, SIGNAL(triggered()), this, SLOT(About()));
	connect(ui.actionStart, SIGNAL(triggered()), this, SLOT(startRender()));
	connect(timerRender, SIGNAL(timeout()), this, SLOT(OnRenderData()));

	//////////////////////////////////////////////////////////////////////////
	world = new World;
	world->build();
	renderThread = new RenderThread(world);
	
	//////////////////////////////////////////////////////////////////////////
	statusBar()->showMessage(tr("Press F5 Build"), 0);
}

// loadImage
void RayTraceWindows::loadImage(QString path)
{
	// default
	QImage* img = new QImage;
	if (!img->load("../../../media/image/desktop.jpg")) //¼ÓÔØÍ¼Ïñ
	{
		QMessageBox::information(this,
			QString::fromLocal8Bit("´ò¿ªÍ¼ÏñÊ§°Ü"),
			QString::fromLocal8Bit("´ò¿ªÍ¼ÏñÊ§°Ü!"));
		delete img;
		return;
	}

	float oriwidth = img->width() / 2;
	float oriheight = img->height() / 2;
	QImage scaled_img = img->scaled(oriwidth, oriheight, Qt::IgnoreAspectRatio);
	ui.renderImage->setPixmap(QPixmap::fromImage(scaled_img));
}

// GetInstance
RayTraceWindows* RayTraceWindows::GetInstance()
{

	static RayTraceWindows* raytracewindows = new RayTraceWindows();
	return raytracewindows;
}

// ~RayTraceWindows
RayTraceWindows::~RayTraceWindows()
{

	if (world != NULL)
	{
		delete world;
	}

	if (timerRender != NULL)
	{
		timerRender->stop();
		disconnect(timerRender, SIGNAL(timeout()), this, SLOT(OnRenderData()));
		delete timerRender;
	}

	// thread stop;
	if (renderThread && renderThread->isRunning())
	{
		renderThread->stop();
		renderThread->wait();
	}


	if (renderThread != NULL)
		delete renderThread;

}

// new file
void RayTraceWindows::newFile()
{
	QString fileName = QFileDialog::getOpenFileName(this);
	if (!fileName.isEmpty())
		loadFile(fileName);
}

// openFile
void RayTraceWindows::openFile()
{
	statusBar()->showMessage(tr("Open"), 2000);
}

// start render
void RayTraceWindows::startRender()
{
	world->paintArea = renderThread;
	timerRender->start(30);
	if (renderThread)
	{
		renderThread->start();
	}
}

// about
void RayTraceWindows::About()
{
	QMessageBox::about(this, tr("About Application"),
		QString::fromLocal8Bit("<<Ray Tracing from the ground up>> "));
}

// loadfile
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

// set RenderImage
void RayTraceWindows::SetRenderImage(QPixmap& pixmap)
{
	if (!pixmap.isNull())
	{
		ui.renderImage->setPixmap(pixmap);
	}
}

// OnRenderData
void RayTraceWindows::OnRenderData()
{
	SetRenderImage(renderThread->GetPixMap());
	statusBar()->showMessage(tr("Rendering:") + QString::number(renderThread->GetProcess() * 100, 'g', 4) + "%");
	if (1 == renderThread->IsComplete())
	{
		statusBar()->showMessage(tr("Rendering:Complete ") + QString::number(renderThread->GetWidth()) + "X" + QString::number(renderThread->GetHeight()));
		renderThread->stop();
		timerRender->stop();
	}
}

//////////////////////////////////////////////////////////////////////////
// KeyInput
//////////////////////////////////////////////////////////////////////////

// keyPressEvent
void RayTraceWindows::keyPressEvent(QKeyEvent * evt)
{
	__super::keyPressEvent(evt);

	switch (evt->key())
	{
	case Qt::Key_Escape:
		this->close();
		break;

	case Qt::Key_F5:
		startRender();
		break;
	case Qt::Key_E:
		ui.debuginfo->insertPlainText("Windows: "+QString::number(ui.renderImage->width())+"*"+QString::number(ui.renderImage->height())+"\r\n");
		break;
	case Qt::Key_R:
		if (renderThread)
		{
			ui.debuginfo->insertPlainText("Render: " + QString::number(renderThread->GetWidth()) + "*" + QString::number(renderThread->GetHeight()) + "\r\n");
		}
		break;
	default:
		break;
	}
};

// keyReleaseEvent
void RayTraceWindows::keyReleaseEvent(QKeyEvent * evt)
{
	__super::keyReleaseEvent(evt);
//	ui.debuginfo->insertPlainText(evt->text() +"=" + QString::number(evt->key())+" ");
};
