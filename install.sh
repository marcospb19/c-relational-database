#!/bin/bash

\time -f " Time: %es" \
gcc -Werror -Wall source/struct.c source/command.c source/list.c source/colors.c source/messages.c source/tables.c main.c -o sgbd && \
echo " Build successful"
