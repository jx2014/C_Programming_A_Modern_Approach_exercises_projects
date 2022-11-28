cmake_minimum_required(VERSION 3.7...3.23)
project(cal VERSION 0.1.0
                DESCRIPTION "Exercises from Chapter 19"
                LANGUAGES C)

include(CTest)
enable_testing()

# ch19_exercise3 part (a), implementing queue.c with fixed-length array.
# add_executable(ch19_exercise3 ch19_exercise3.c queue.c)

# ch19_exercise3 part (b), implementing queue.c with linked-list
# add_executable(ch19_exercise3 ch19_exercise3.c queue_linked-list.c)

# ch19_exercise4 part (a), implementing stack type with fixed-length array.
# add_executable(ch19_exercise4 ch19_exercise4.c stack_exercise4a.c)

# ch19_exercise4 part (b), implementing stack type with linked-list
#add_executable(ch19_exercise4 ch19_exercise4.c stack_exercise4b.c)

# ch19_exercise5, implementing queue type with fixed-length array.
# add_executable(ch19_exercise5 ch19_exercise5.c queue_exercise5.c)

# ch19_exercise6, implementing stack type with fixed-length array.
# exercise 6 (a)
# add_executable(ch19_exercise6 ch19_exercise6.c stackADT.c)
# exercise 6 (b)
# add_executable(ch19_exercise6 ch19_exercise6.c stackADT2.c)
# exercise 6 (c)
# add_executable(ch19_exercise6 ch19_exercise6.c stackADT3.c)

# ch19_exercise7, modify stackADT2.c so that push function will
# automaticaly allocate memory when full.
# add_executable(ch19_exercise7 ch19_exercise7.c stackADT2_exercise7.c)


# ch23_exercise3 modify stackADT2_exercise.c to use assert for testing errors 
# instead of the if statement.
# automaticaly allocate memory when full.
# add_executable(ch24_exercise3 ch24_exercise3.c stackADT2_exercise3.c)

# ch24_exercise5
# modify inventory from chapter 16, using setjmp, and long_jmp to reutrn to main
add_executable(ch24_exercise5 ch24_exercise5.c readline.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
