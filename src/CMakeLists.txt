cmake_minimum_required(VERSION 3.21)

add_executable("33_Homework_3" main.cpp ${MY_INCLUDE_DIR}/function.h ${MY_INCLUDE_DIR}/classes.h ${MY_INCLUDE_DIR}/structures.h)
target_include_directories("33_Homework_3" PUBLIC ${MY_INCLUDE_DIR})