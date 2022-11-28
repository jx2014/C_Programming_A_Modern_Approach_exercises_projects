cmake_minimum_required(VERSION 3.7...3.23)
project(justify VERSION 0.1.0
                DESCRIPTION "Project from text book"
                LANGUAGES C)

include(CTest)
enable_testing()

add_executable(justify justify.c line.c word.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
