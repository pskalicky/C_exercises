cmake_minimum_required(VERSION 3.31)
project(struct C)

set(CMAKE_C_STANDARD 11)

add_executable(struct stud_ev.c
        stud_ev.h
        test_stud_ev.h
        test_stud_ev.c)
