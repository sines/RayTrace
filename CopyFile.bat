@ECHO OFF
ECHO ############################################################
ECHO #	Generating Visual Studio Project Files
ECHO ############################################################
echo f|xcopy.exe /r /y bin\RayTraceLib.lib lib\RayTraceLib.lib
ECHO ############################################################
ECHO #	Finished!
ECHO ############################################################

pause