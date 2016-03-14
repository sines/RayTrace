set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4251 /wd4275 /wd4193")

FILE(GLOB HEADERS "*.h")
FILE(GLOB SOURCES "*.cpp")



set(All_Files ${HEADERS} ${SOURCES})
source_group_by_dir(All_Files)
#add_library(RayTraceLib STATIC ${HEADERS}${SOURCES})


add_definitions("-DTIXML_USE_STL")
add_definitions("-DHIDSDK_EXPORTS")
add_definitions("-DOGREMAX_SHARED_LIBRARY_EXPORT")
add_definitions(-DUNICODE -D_UNICODE)
LINK_DIRECTORIES("${PROJECT_SOURCE_DIR}/lib/")
set(CMAKE_LINK_LIBRARY_SUFFIX "")

INCLUDE_DIRECTORIES("./")
INCLUDE_DIRECTORIES("../include/")
INCLUDE_DIRECTORIES("include/")