#!/bin/bash
\time -f " Time: %es" gcc -Werror -Wall libraries/struct.c libraries/command.c libraries/list.c libraries/colors.c libraries/messages.c libraries/tables.c main.c -o sgbd && echo " Build successful"
