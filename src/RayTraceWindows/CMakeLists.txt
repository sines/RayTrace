INCLUDE_DIRECTORIES("./")
INCLUDE_DIRECTORIES("include/")
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/RayTraceLib/World/")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4251 /wd4275 /wd4193")

############################################################
# qt
############################################################
#set(CAMKE_INSTALL_PREFIX "${QT_ROOT}")
#set(CMAKE_PREFIX_PATH ${QT_ROOT})
#message("!!!cmake: ${CMAKE_PREFIX_PATH}")
#message(${QT_ROOT})
#message("!!!cmake: ${CMAKE_PREFIX_PATH}")

FILE(GLOB HEADERS "src/*.h")
FILE(GLOB SOURCES "src/*.cpp")
FILE(GLOB FORMS "form/*.ui")
add_definitions("-DTIXML_USE_STL")
add_definitions(-DUNICODE -D_UNICODE)
add_definitions(/Zc:wchar_t-)
add_executable(RayTraceWindows ${HEADERS} ${SOURCES} ${HEADERS_MOC} ${FORMS_HEADERS} ${QRC_RES})
TARGET_LINK_LIBRARIES(RayTraceWindows ${QT_LIBRARIES} RayTraceLib)
set(CMAKE_LINK_LIBRARY_SUFFIX "")

SET_TARGET_PROPERTIES (RayTraceWindows PROPERTIES WIN32_EXECUTABLE TRUE)