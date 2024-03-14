cmake_minimum_required(VERSION 3.29.0)
project(project VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(SortedBagExecutable Data_Structure/SortedBag/SortedBag/App.cpp Data_Structure/SortedBag/SortedBag/ExtendedTest.cpp Data_Structure/SortedBag/SortedBag/ShortTest.cpp Data_Structure/SortedBag/SortedBag/SortedBag.cpp Data_Structure/SortedBag/SortedBag/SortedBagIterator.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
