#ifndef TABLES_H
#define TABLES_H
#include "tables.c"
#endif

int strcommand(char string[] , char command[]);
// Similar to strcmp, returns 1 if command is inside of the string (instead of returning 0, like strcmp)

int createTable(char nameOfTable[]);
// Creates tables that can store integers, decimal numbers, characters and strings
// First adds the table to the listOfTables.txt, and then creates the table

int listTables();
// List all the tables inside of listOfTables.txt

int createLine();
// Inserts a line
