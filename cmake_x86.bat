@ECHO OFF
ECHO ############################################################
ECHO #	Generating Visual Studio Project Files
ECHO ############################################################

SET SDK_DIR=D:\
SET QT_ROOT=%SDK_DIR%Qt\Qt5.5.0\5.5\msvc2013

rmdir /S /Q build_x86_vc120
mkdir build_x86_vc120
cd build_x86_vc120
cmake.exe -L -DX86:BOOL=ON -DX64:BOOL=OFF  -DQT_ROOT:PATH=%QT_ROOT% ../ -G"Visual Studio 12 2013"

ECHO ############################################################
ECHO #	Finished!
ECHO ############################################################

pause