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

project(KapEngine LANGUAGES CXX)
set(CMAKE_VERBOSE_MAKEFILE ON)

option(KAPENGINE_THREAD "Build the engine with thread" OFF)
option(KAPENGINE_BETA "Build the engine with beta additionals" OFF)
option(KAPENGINE_DEBUG "Build the engine in debug mode" OFF)
option(KAPENGINE_EDITOR "Build the engine in editor mode (only editor should use this option)" OFF)

set(CMAKE_CXX_STANDARD 17)

# KapEngine includes
include(${KapEngine_SOURCE_DIR}/CMake/engine_include.cmake)

# KapEngine sources
file(GLOB_RECURSE SOURCES ${KapEngine_SOURCE_DIR}/KapEngine/*.cpp)

add_library(KapEngine STATIC ${SOURCES} ${HEADERS})

# C++ Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -g")

# Linker flags
set_target_properties(KapEngine PROPERTIES LINK_FLAGS "-pthread")

if (${KAPENGINE_THREAD})
	add_compile_options(-DKAPENGINE_THREAD_ACTIVE=true)
endif()

if (${KAPENGINE_BETA})
	add_compile_options(-DKAPENGINE_BETA_ACTIVE=true)
endif()

if (${KAPENGINE_DEBUG})
	add_compile_options(-DKAPENGINE_DEBUG_ACTIVE=true)
endif()

if (${KAPENGINE_EDITOR})
	add_compile_options(-DKAPENGINE_EDITOR_ACTIVE=true)
endif()
