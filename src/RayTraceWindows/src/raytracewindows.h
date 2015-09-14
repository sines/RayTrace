#ifndef RAYTRACEWINDOWS_H
#define RAYTRACEWINDOWS_H

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
};

#endif // RAYTRACEWINDOWS_H
