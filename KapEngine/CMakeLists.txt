project(KapEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES ${KapEngine_SOURCE_DIR}/*.cpp)

add_library(KapEngine SHARED ${SOURCES} ${HEADERS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

set_target_properties(KapEngine PROPERTIES LINK_FLAGS "-pthread")
