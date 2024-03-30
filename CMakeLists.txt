cmake_minimum_required(VERSION 3.29.0)
project(project VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(SortedBagExecutable Data_Structure/SortedIteratedList/SortedIteratedList/App.cpp Data_Structure/SortedIteratedList/SortedIteratedList/ExtendedTest.cpp Data_Structure/SortedIteratedList/SortedIteratedList/ShortTest.cpp Data_Structure/SortedIteratedList/SortedIteratedList/SortedIteratedList.cpp Data_Structure/SortedIteratedList/SortedIteratedList/ListIterator.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
