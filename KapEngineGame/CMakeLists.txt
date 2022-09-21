project(KapGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES ${KapGame_SOURCE_DIR}/*.cpp)

add_executable(KapGame ${SOURCES} ${HEADERS})

target_link_libraries(KapGame KapEngine)

target_include_directories(KapGame PRIVATE
        ${HEADERS}
        ${KapGame_SOURCE_DIR}
        ${KapGame_SOURCE_DIR}/Assets/Components)
