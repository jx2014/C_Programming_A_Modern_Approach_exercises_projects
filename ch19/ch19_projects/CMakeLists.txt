cmake_minimum_required(VERSION 3.7...3.23)
project(cal VERSION 0.1.0
                DESCRIPTION "Projects from Chapter 19"
                LANGUAGES C)

include(CTest)
enable_testing()

# ch19 project 1, rewrite Project 1 from Chapter 10 using one of the ADTs.
#add_executable(ch19_project1 ch19_project1.c stackADT2_exercise7.c)

# ch19 project 2, rewrite Project 6 from Chapter 10 using one of the ADTs.
#add_executable(ch19_project2_RPN ch19_project2_RPN.c stackADT2_exercise7.c)

# ch19 project 3, modify stackADT3 and stackclient
#add_executable(ch19_project3_stackclient ch19_project3_stackclient.c stackADT3_project3.c)

# ch19 project 4, modify stackADT3 and stackclient by removing Item type.
#add_executable(ch19_project4_stackclient ch19_project4_stackclient.c stackADT3_project4.c)

# ch19 project 5 and 6, create queueADT.h and queueADT.c, and use an abtratry type *Queue to create queue object
#add_executable(ch19_project5_queueclient ch19_project5_queueclient.c queueADT.c)

# ch19 project 7, modify project 5/6 to use linked-list (reference exercise 3(b))
add_executable(ch19_project7_queueclient ch19_project7_queueclient.c queueADT_project7.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
