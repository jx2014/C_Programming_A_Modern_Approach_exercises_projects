cmake_minimum_required(VERSION 3.7...3.23)
project(RPN VERSION 0.1.0
                DESCRIPTION "Project 3 from text book chapter 15 "
                LANGUAGES C)

include(CTest)
enable_testing()

add_executable(calc calc.c stack.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
