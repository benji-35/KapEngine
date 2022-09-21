project(KapEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES ${KapEngine_SOURCE_DIR}/*.cpp)

add_library(KapEngine SHARED ${SOURCES})

target_include_directories(KapEngine PRIVATE
        ${KapEngine_SOURCE_DIR}/Components
        ${KapEngine_SOURCE_DIR}/Components/Transform
        ${KapEngine_SOURCE_DIR}/Components/Camera

        ${KapEngine_SOURCE_DIR}/Component
        ${KapEngine_SOURCE_DIR}/GameObject

        ${KapEngine_SOURCE_DIR}/Engine
        ${KapEngine_SOURCE_DIR}/Errors

        ${KapEngine_SOURCE_DIR}/SceneManagement/Scene
        ${KapEngine_SOURCE_DIR}/SceneManagement/SceneManager

        ${KapEngine_SOURCE_DIR}/Tools
        ${KapEngine_SOURCE_DIR}/Debug

        ${KapEngine_SOURCE_DIR}/GraphicalLib

        ${KapEngine_SOURCE_DIR}/Events/Input
        ${KapEngine_SOURCE_DIR}/Events/Mouse
        ${KapEngine_SOURCE_DIR}/Events/Manager

        ${KapEngine_SOURCE_DIR}/Legacy/Graphical

        ${KapEngine_SOURCE_DIR}/Events/Action

        ${KapEngine_SOURCE_DIR}/Time

        ${KapEngine_SOURCE_DIR}/Entity

        ${KapEngine_SOURCE_DIR}/SpecialOperation
        ${KapEngine_SOURCE_DIR}/SpecialOperation/AsyncOperation
        ${KapEngine_SOURCE_DIR}/SpecialOperation/SyncOperation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

set_target_properties(KapEngine PROPERTIES LINK_FLAGS "-pthread")
