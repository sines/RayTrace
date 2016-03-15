set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4251 /wd4275 /wd4193")
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

FILE(GLOB_RECURSE HEADERS "*.h")
FILE(GLOB_RECURSE RAYLIBHEAD "../RayTraceLib/*.h")
FILE(GLOB_RECURSE SOURCES "*.cpp")
FILE(GLOB_RECURSE SOURCES_UI "*.ui" "*.qrc")
set(All_Files ${HEADERS} ${SOURCES} ${SOURCES_UI})
source_group_by_dir(All_Files)
include_add_by_dir(HEADERS)
include_add_by_dir(RAYLIBHEAD)
include_add_by_dir(SOURCES_UI)
############################################################
# qt
############################################################
set(QT_QMAKE_EXECUTABLE ${QT_ROOT}/bin/qmake)
set(CMAKE_AUTOMOC ON)
find_package(qt5 REQUIRED)
ADD_DEFINITIONS (${QT_DEFINITIONS})

message("!!!gname: ${QT_ROOT}")
INCLUDE_DIRECTORIES(${QT_ROOT}/include)
INCLUDE_DIRECTORIES(${QT_ROOT}/lib)
FILE(GLOB QT_RUNTIME ${QT_ROOT}/bin/*.dll)
INSTALL(FILES ${QT_RUNTIME} DESTINATION .)
############################################################

add_executable(RayTraceWindows ${All_Files})

############################################################

add_definitions("-DTIXML_USE_STL")
add_definitions(-DUNICODE -D_UNICODE)
add_definitions(/Zc:wchar_t-)

target_link_libraries(RayTraceWindows  ${QT_LIBRARIES})
TARGET_LINK_LIBRARIES(RayTraceWindows qtmaind.lib.lib Qt5Cored.lib.lib Qt5Guid.lib Qt5Widgetsd.lib Qt5Quick.lib)
TARGET_LINK_LIBRARIES(RayTraceWindows RayTraceLib)

set(CMAKE_LINK_LIBRARY_SUFFIX "")

SET_TARGET_PROPERTIES (RayTraceWindows PROPERTIES WIN32_EXECUTABLE TRUE)