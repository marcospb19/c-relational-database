#ifndef TABLES_H
#define TABLES_H


int searchData(char nameOfTable[]);
// Search for data inside of a choosen table

int createTable(char nameOfTable[]);
// Creates tables that can store integers, decimal numbers, characters and strings
// First adds the table to the listOfTables.txt, and then creates the table

int copyAndPaste(char source[] , char destination[] , int numberOfLines);
// Copys everything inside of source to destination
// Used to modify tables, for example

int createLine();
// Inserts a line

int createColumn(char nameOfTable[]);
// Creates a column

int listValues(char nameOfTable[]);
// List all values of an table

int tableExists(char nameOfTable[]);
// Try to open table to check if table exists


#endif
