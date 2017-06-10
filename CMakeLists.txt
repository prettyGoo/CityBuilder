cmake_minimum_required(VERSION 3.7)
project(CityBuilder)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp game.cpp)
# Comment for build
add_executable(CityBuilder ${SOURCE_FILES})

# Comment for IDE support
#add_custom_target(CityBuilders COMMAND make -C ${CityBuilder_SOURCE_DIR}
#        CLION_EXE_DIR=${PROJECT_BINARY_DIR})