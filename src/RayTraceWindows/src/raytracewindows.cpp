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

void RayTraceWindows::About()
{
	QMessageBox::about(this, tr("About Application"),
		tr("This <b>Application</b> describes the step-by-step process of writing a ray tracer from scratch. Using numerous examples that illustrate the ray-tracing concept and processes in detail, the author presents a ray-tracer design and sample code that allows for extensibility, efficiency of the algorithms, and readability. Chapters begin with stated aims and include questions and exercises that allow the reader to apply the material presented. "));
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