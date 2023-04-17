cmake_minimum_required(VERSION 3.18.4)
project(try)

set(CMAKE_CXX_STANDARD 11)

add_executable(try main.cpp time.cpp control.cpp QR.cpp state_machine.cpp)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})


include_directories(
/usr/lib
/usr/include
)


set(LIBZBAR_PATH /usr/lib/arm-linux-gnueabihf/) 
find_library(LIBZBAR_LIBRARY NAMES zbar HINTS ${LIBZBAR_PATH})
target_link_libraries(try ${LIBZBAR_LIBRARY})


find_library(wiringPi_LIB wiringPi)
target_link_libraries(${PROJECT_NAME} ${wiringPi_LIB})

