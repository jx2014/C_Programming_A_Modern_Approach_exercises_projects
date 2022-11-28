cmake_minimum_required(VERSION 3.7...3.23)
project(main VERSION 0.1.0
                DESCRIPTION "This is a test project for cmake"
                LANGUAGES C)

include(CTest)
enable_testing()

add_executable(main_func bar_test.c barz.c bar.c foo.c)
#add_executable(main testdebug.c) # EXERCISE 4


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
