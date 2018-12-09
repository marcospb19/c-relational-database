cmake_minimum_required (VERSION 3.10.2)
project(sgbd C)

include_directories(source)

set(SOURCES source/struct.c source/command.c source/list.c source/colors.c source/messages.c source/tables.c main.c)

add_executable(sgbd ${SOURCES})
