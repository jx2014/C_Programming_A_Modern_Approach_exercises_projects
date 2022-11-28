cmake_minimum_required(VERSION 3.7...3.23)
project(main VERSION 0.1.0
                DESCRIPTION "All exercises from Chapter 15"
                LANGUAGES C)

include(CTest)
enable_testing()

#add_executable(main testdebug.c) # EXERCISE 4
add_executable(main main.c f1.c f2.c) # EXERCISE 5


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
