cmake_minimum_required (VERSION 3.10.2)
project(sgbd C)

include_directories(libraries)

set(SOURCES libraries/struct.c libraries/command.c libraries/list.c libraries/colors.c libraries/messages.c libraries/tables.c main.c)

add_executable(sgbd ${SOURCES})
