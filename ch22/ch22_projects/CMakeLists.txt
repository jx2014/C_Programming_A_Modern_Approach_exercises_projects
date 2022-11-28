cmake_minimum_required(VERSION 3.7...3.23)
project(inventory VERSION 0.1.0
                DESCRIPTION "Chapter 22 Projects"
                LANGUAGES C)

include(CTest)
enable_testing()

# Chapter 22 Project 8 - modify inventory_4.c, project 4 from 
# chapter 16 by adding saving and reloading database.
# add_executable(inventory inventory_5.c readline.c)


# Chapter 22 Project 9 - this is the function needed to generate
# the test file.
# add_executable(inventory inventory_6.c readline.c)
# add_executable(merge project_9_merge_inventory.c)

# Chapter 22 Project 10
# modify inventory2.c from Section 17.5 by adding dump and restore.
# add_executable(inventory_linked_list project_10_inventory_linked_list.c readline.c)

# Chapter 22 Project 15
# modify justify.c from Section 15.3 so that it reads from one text file
# and writes to another. The program will obtain the names of both files
# from the command line
add_executable(justify justify.c line.c word.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
