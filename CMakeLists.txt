cmake_minimum_required(VERSION 3.24)
project(test2)

set(CMAKE_CXX_STANDARD 11)

add_executable(final_try main.cpp QR.cpp state_machine.cpp)


find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})


find_package(ZBar REQUIRED)
include_directories(${ZBAR_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${ZBAR_LIBRARIES})


find_package(wiringPi REQUIRED)
include_directories(${wiringPi_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${wiringPi_LIB})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
