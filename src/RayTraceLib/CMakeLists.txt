set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4251 /wd4275 /wd4193")

FILE(GLOB_RECURSE HEADERS "*.h")
FILE(GLOB_RECURSE WINHEADERS "../RayTraceWindows/*.H")
FILE(GLOB_RECURSE SOURCES "*.cpp")

set(All_Files ${HEADERS} ${SOURCES})
source_group_by_dir(All_Files)
include_add_by_dir(HEADERS)
include_add_by_dir(WINHEADERS)
add_library(RayTraceLib STATIC ${All_Files})


add_definitions("-DTIXML_USE_STL")
add_definitions("-DHIDSDK_EXPORTS")
add_definitions("-DOGREMAX_STATIC_LIBRARY_EXPORT")
add_definitions(-DUNICODE -D_UNICODE)
LINK_DIRECTORIES("${PROJECT_SOURCE_DIR}/lib/")
set(CMAKE_LINK_LIBRARY_SUFFIX "")
