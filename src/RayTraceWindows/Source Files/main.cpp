#include "raytracewindows.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RayTraceWindows w;
	w.show();
	return a.exec();
}
