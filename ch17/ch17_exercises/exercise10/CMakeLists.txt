cmake_minimum_required(VERSION 3.7...3.23)
project(inventory VERSION 0.1.0
                DESCRIPTION "Exercise 10 from text book chapter 10, modify Inventory code from 16.2 "
                LANGUAGES C)

include(CTest)
enable_testing()

add_executable(inventory inventory.c readline.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
