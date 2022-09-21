cmake_minimum_required(VERSION 3.16)

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR} AND NOT WIN32)
	message(FATAL_ERROR
	"You can not use CMake to build from the root of it's source tree!\n"
	"Remove the CMakeCache.txt file from this directory, then create a separate directory\n"
	"(either below this directory or elsewhere), and then re-run CMake from there.")
endif(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR} AND NOT WIN32)

project(KapEngine)

# Common includes
include_directories(KapEngine/Components)
include_directories(KapEngine/Components/Transform)
include_directories(KapEngine/Components/Camera)

include_directories(KapEngine/Component)
include_directories(KapEngine/GameObject)

include_directories(KapEngine/Engine)
include_directories(KapEngine/Errors)

include_directories(KapEngine/SceneManagement/Scene)
include_directories(KapEngine/SceneManagement/SceneManager)

include_directories(KapEngine/Tools)
include_directories(KapEngine/Debug)

include_directories(KapEngine/GraphicalLib)

include_directories(KapEngine/Events/Input)
include_directories(KapEngine/Events/Mouse)
include_directories(KapEngine/Events/Manager)

include_directories(KapEngine/Legacy/Graphical)

include_directories(KapEngine/Events/Action)

include_directories(KapEngine/Time)

include_directories(KapEngine/Entity)

include_directories(KapEngine/SpecialOperation)
include_directories(KapEngine/SpecialOperation/AsyncOperation)
include_directories(KapEngine/SpecialOperation/SyncOperation)

# Modules
add_subdirectory(KapEngine)
add_subdirectory(KapEngineGame)
