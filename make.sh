#!/bin/bash
gcc -Werror -Wall libraries/list.c libraries/colors.c libraries/messages.c libraries/tables.c main.c -o main.out && echo "Build successful."

