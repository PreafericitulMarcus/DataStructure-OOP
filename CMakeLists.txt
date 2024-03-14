cmake_minimum_required(VERSION 3.29.0)
project(project VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Lab3Executable OOP/lab3/main.cpp OOP/lab3/problem2.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
