cmake_minimum_required(VERSION 3.15)
project(Lab2___Memory_Allocation C)

set(CMAKE_C_STANDARD 99)

add_executable(cpu cpu.c)
add_executable(memory memory.c oslabs.h)
add_executable(virtual virtual.c)
add_executable(disk disk.c)