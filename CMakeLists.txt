##
## ██╗  ██╗ █████╗ ██████╗ ███████╗███╗   ██╗ ██████╗ ██╗███╗   ██╗███████╗
## ██║ ██╔╝██╔══██╗██╔══██╗██╔════╝████╗  ██║██╔════╝ ██║████╗  ██║██╔════╝
## █████╔╝ ███████║██████╔╝█████╗  ██╔██╗ ██║██║  ███╗██║██╔██╗ ██║█████╗
## ██╔═██╗ ██╔══██║██╔═══╝ ██╔══╝  ██║╚██╗██║██║   ██║██║██║╚██╗██║██╔══╝
## ██║  ██╗██║  ██║██║     ███████╗██║ ╚████║╚██████╔╝██║██║ ╚████║███████╗
## ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝
##
## by Benjamin DELVERT

#
# DO NOT TOUCH THIS FILE
# ANY CHANGES CAN DESTROY THE PROCESS TO COMPILE
#

cmake_minimum_required(VERSION 3.16)

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR} AND NOT WIN32)
	message(FATAL_ERROR
	"You can not use CMake to build from the root of it's source tree!\n"
	"Remove the CMakeCache.txt file from this directory, then create a separate directory\n"
	"(either below this directory or elsewhere), and then re-run CMake from there.")
endif(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR} AND NOT WIN32)

option(BUILD_TESTS "Build unit tests in build directory" OFF)

if(BUILD_TESTS)

	#build unit tests

	project(KapEngineTest LANGUAGES CXX)

	set(CMAKE_CXX_STANDARD 17)

	# KapEngine includes
	include(${KapEngine_SOURCE_DIR}/CMake/engine_include.cmake)

	# test includes
	include_directories(${KapEngine_SOURCE_DIR}/Tests/)
	# test files
	file(GLOB_RECURSE SOURCES ${KapEngine_SOURCE_DIR}/Tests/*.cpp)

	add_executable(KapEngineTest ${SOURCES} ${HEADERS})

	#include KapEngine library
	target_link_libraries(KapEngineTest ${KapEngine_SOURCE_DIR}/build/libKapEngine.a)

	# C++ Flags
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

	# Linker flags
	set_target_properties(KapEngineTest PROPERTIES LINK_FLAGS "-pthread -lcriterion")
else ()

	#build library

	project(KapEngine LANGUAGES CXX)

	set(CMAKE_CXX_STANDARD 17)

	# KapEngine includes
	include(${KapEngine_SOURCE_DIR}/CMake/engine_include.cmake)

	# KapEngine sources
	file(GLOB_RECURSE SOURCES ${KapEngine_SOURCE_DIR}/KapEngine/*.cpp)

	add_library(KapEngine STATIC ${SOURCES} ${HEADERS})

	# C++ Flags
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

	# Linker flags
	set_target_properties(KapEngine PROPERTIES LINK_FLAGS "-pthread")

endif()