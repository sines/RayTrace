@ECHO OFF
ECHO ############################################################
ECHO #	Generating ui Files
ECHO ############################################################

uic mainwindow.ui -o ..\src\mainwindow.h
uic mainwindow.ui -o ..\src\mainwindow.cpp

setlocal
if errorlevel 1 goto VCEnd
uic mainwindow.ui -o ..\src\ui_mainwindow.h
if errorlevel 1 goto VCEnd
endlocal

ECHO ############################################################
ECHO #	Finished!
ECHO ############################################################