#ifndef RAYTRACEWINDOWS_H
#define RAYTRACEWINDOWS_H
#include <QtWidgets/QPlainTextEdit>

#include <QtWidgets/QMainWindow>
#include "ui_raytracewindows.h"
#include "World.h"
#include "RenderThread.h"

class RayTraceWindows : public QMainWindow
{
	Q_OBJECT

public:
	RayTraceWindows(QWidget *parent = 0);
	~RayTraceWindows();

private:
	Ui::RayTraceWindowsClass ui;

private:
	QPlainTextEdit *textEdit;

	void loadFile(const QString &fileName);

	private slots:
	// file
		void newFile();
		void openFile();
		void About();

	// render
		void startRender();

protected:
	World* world;
	RenderThread* renderThread;
};

#endif // RAYTRACEWINDOWS_H