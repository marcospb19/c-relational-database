cmake_minimum_required (VERSION 3)
project(sgbd C)

include_directories(src)

set(SOURCES src/struct.c src/command.c src/list.c src/colors.c src/messages.c src/tables.c src/main.c)

add_executable(sgbd ${SOURCES})
