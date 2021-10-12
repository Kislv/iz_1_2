cmake_minimum_required(VERSION 3.16)

project(test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_SOURCE_FILES fib.cpp)
add_library(fib STATIC ${LIB_SOURCE_FILES})

add_executable(main main.cpp)
target_link_libraries(main fib)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(fib_test fib_test.cpp)
target_link_libraries(fib_test gtest pthread)
target_link_libraries(fib_test ${GTEST_LIBRARIES} fib)