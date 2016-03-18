#ifndef RAYTRACEWINDOWS_H
#define RAYTRACEWINDOWS_H
#include <QtWidgets/QPlainTextEdit>

#include <QtWidgets/QMainWindow>
#include "ui_raytracewindows.h"
#include "World.h"
#include "RenderThread.h"
#include <QTimer>

class RayTraceWindows : public QMainWindow
{
	Q_OBJECT

private:
	RayTraceWindows(QWidget *parent = 0);
	~RayTraceWindows();


public:
	static RayTraceWindows* GetInstance(void);

	void SetRenderImage(QPixmap& pixmap);
protected slots:
	void OnRenderData();

	void keyPressEvent(QKeyEvent * evt);
	void keyReleaseEvent(QKeyEvent * evt);

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
		void loadImage(QString path = "../../../media/image/desktop.jpg");
protected:
	World* world;
	RenderThread* renderThread;
	QTimer* timerRender;
};

#endif // RAYTRACEWINDOWS_H
