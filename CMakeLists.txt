cmake_minimum_required(VERSION 3.29.0)
project(project VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Bag Data_Structure/Matrix/Matrix/App.cpp Data_Structure/Matrix/Matrix/ExtendedTest.cpp Data_Structure/Matrix/Matrix/ShortTest.cpp Data_Structure/Matrix/Matrix/Matrix.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
