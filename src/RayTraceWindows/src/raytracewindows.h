#ifndef RAYTRACEWINDOWS_H
#define RAYTRACEWINDOWS_H
#include <QPlainTextEdit>

#include <QtWidgets/QMainWindow>
#include "ui_raytracewindows.h"

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
};

#endif // RAYTRACEWINDOWS_H
