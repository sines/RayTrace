set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4251 /wd4275 /wd4193")

FILE(GLOB_RECURSE HEADERS "*.h")
FILE(GLOB_RECURSE WINHEADERS "../RayTraceWindows/*.H")
FILE(GLOB_RECURSE SOURCES "*.cpp")
FILE(GLOB_RECURSE BUILDCPP "build/*.cpp")
list(REMOVE_ITEM SOURCES ${BUILDCPP})

set(All_Files ${HEADERS} ${SOURCES})
source_group_by_dir(All_Files)
include_add_by_dir(HEADERS)
include_add_by_dir(WINHEADERS)
include_add_by_dir(BUILDCPP)


add_library(RayTraceLib STATIC ${All_Files})

############################################################
# qt
############################################################
set(QT_QMAKE_EXECUTABLE ${QT_ROOT}/bin/qmake)
set(CMAKE_PREFIX_PATH ${QT_ROOT})
set(CAMKE_INSTALL_PREFIX ${QT_ROOT})
set(CMAKE_MODULE_PATH "${QT_ROOT}/lib/cmake")
find_package(Qt5Widgets)
INCLUDE_DIRECTORIES(${QT_ROOT}/include)
include_directories(${Qt5Widgets_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${Qt5Core_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS} ${Qt5OpenGL_INCLUDE_DIRS} ${Qt5Xml_INCLUDE_DIRS})

add_definitions("-DTIXML_USE_STL")
add_definitions("-DHIDSDK_EXPORTS")
add_definitions("-DOGREMAX_STATIC_LIBRARY_EXPORT")
add_definitions(-DUNICODE -D_UNICODE)
#LINK_DIRECTORIES("${PROJECT_SOURCE_DIR}/lib/")
set(CMAKE_LINK_LIBRARY_SUFFIX "")

#ADD_CUSTOM_COMMAND(
#   TARGET RayTraceLib
#    POST_BUILD
#    COMMAND -E xcopy "${PROJECT_SOURCE_DIR}/bin/RayTraceLib.lib" "${PROJECT_SOURCE_DIR}/lib/RayTraceLib.lib"
#	COMMENT "copying lib …"
#)
