#include "raytracewindows.h"
#include <QtWidgets/QApplication>

#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )
/*

#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )
#pragma comment( linker, "/subsystem:console /entry:mainCRTStartup" )
#pragma comment( linker, "/subsystem:console /entry:WinMainCRTStartup" )

*/
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RayTraceWindows w;
	w.show();
	return a.exec();
}
