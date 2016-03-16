set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS} /wd4251 /wd4275 /wd4193")
set(CMAKE_AUTOMOC ON)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

FILE(GLOB_RECURSE HEADERS "*.h")
FILE(GLOB_RECURSE RAYLIBHEAD "../RayTraceLib/*.h")
FILE(GLOB_RECURSE SOURCES "*.cpp")
FILE(GLOB_RECURSE SOURCES_UI "*.ui")
FILE(GLOB_RECURSE SOURCES_QRC "*.qrc")
set(All_Files ${HEADERS} ${SOURCES} ${SOURCES_UI} ${SOURCES_QRC})
source_group_by_dir(All_Files)
include_add_by_dir(HEADERS)
include_add_by_dir(RAYLIBHEAD)
include_add_by_dir(SOURCES_UI)
include_add_by_dir(SOURCES_QRC)
############################################################
# qt
############################################################
set(QT_QMAKE_EXECUTABLE ${QT_ROOT}/bin/qmake)
set(CMAKE_PREFIX_PATH ${QT_ROOT})
set(CAMKE_INSTALL_PREFIX ${QT_ROOT})
set(CMAKE_MODULE_PATH "${QT_ROOT}/lib/cmake")
find_package(Qt5Widgets)

QT5_WRAP_CPP(HEADERS_MOC ${HEADERS})
QT5_WRAP_UI(FORMS_HEADERS ${SOURCES_UI}) 
qt5_add_resources(qrc_FILES ${SOURCES_QRC})

qt5_generate_moc("Source Files/main.cpp" "main.moc")

FILE(GLOB QT_RUNTIME ${QT_ROOT}/bin/*.dll)
INSTALL(FILES ${QT_RUNTIME} DESTINATION .)
############################################################
add_executable(RayTraceWindows ${All_Files} ${qrc_FILES} "main.moc")

############################################################
message("!!!gname: ${QT_ROOT}")
INCLUDE_DIRECTORIES(${QT_ROOT}/include)
include_directories(${Qt5Widgets_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${Qt5Core_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS} ${Qt5OpenGL_INCLUDE_DIRS} ${Qt5Xml_INCLUDE_DIRS})

#LINK_DIRECTORIES("${AUDIERE_DIR}/lib/")

add_definitions(${Qt5Widgets_DEFINITIONS})
add_definitions("-DTIXML_USE_STL")
add_definitions(-DUNICODE -D_UNICODE)
add_definitions(/Zc:wchar_t-)
SET(QT_USE_QTMAIN TRUE)

target_link_libraries(RayTraceWindows Qt5::Widgets)
TARGET_LINK_LIBRARIES(RayTraceWindows RayTraceLib)

set(CMAKE_LINK_LIBRARY_SUFFIX "")
SET_TARGET_PROPERTIES (RayTraceWindows PROPERTIES WIN32_EXECUTABLE TRUE)