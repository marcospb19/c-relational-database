cmake_minimum_required (VERSION 3.10.2)
project(sgbd C)


#Bring the headers
include_directories(libraries/struct.h libraries/commands.h libraries/list.h libraries/colors.h libraries/messages.h libraries/tables.h)

set(SOURCES libraries/struct.c libraries/commands.c libraries/list.c libraries/colors.c libraries/messages.c libraries/tables.c main.c)

add_executable(sgbd ${SOURCES})
 