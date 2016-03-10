#include "raytracewindows.h"
#include <QFile>
#include <QMessageBox>
#include <QTextEdit>
#include <QTextStream>
#include <QFileDialog>

RayTraceWindows::RayTraceWindows(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.statusBar->showMessage(tr("Ready"));
	connect(ui.actionNew, SIGNAL(triggered()), this, SLOT(newFile()));
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
	connect(ui.actionAbout, SIGNAL(triggered()), this, SLOT(About()));
	connect(ui.actionStart, SIGNAL(triggered()), this, SLOT(startRender()));

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
/*
	QPixmap pix;
	pix.load("../../../media/image/desktop.jpg");

	pix = pix.scaled(oriwidth, oriwidth, Qt::KeepAspectRatio);
	ui.renderImage->setPixmap(pix);*/
	ui.renderImage->setPixmap(QPixmap::fromImage(scaled_img));
}


RayTraceWindows::~RayTraceWindows()
{

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