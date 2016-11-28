cmake_minimum_required(VERSION 3.6)
project(imageFormatConverted)

set(CMAKE_CXX_STANDARD 11)

FIND_PACKAGE(OpenCV REQUIRED)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(/usr/local/include /usr/local/include/opencv /usr/local/include/opencv2)

FIND_PACKAGE(Boost COMPONENTS system filesystem REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

set(SOURCE_FILES main.cpp)
add_executable(imageFormatConverted ${SOURCE_FILES})
target_link_libraries(imageFormatConverted ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(imageFormatConverted ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})