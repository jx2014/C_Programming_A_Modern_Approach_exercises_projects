cmake_minimum_required(VERSION 3.7...3.23)
project(remind VERSION 0.1.0
                DESCRIPTION "Project 4 from text book chapter 15 "
                LANGUAGES C)

include(CTest)
enable_testing()

add_executable(remind remind.c readline.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
