#!/bin/bash
clear && clear
valgrind --leak-check=full --log-file="log/valgrindLog.txt" ./sgbd && echo Log created at 'log/valgrindLog.txt'
