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

int createColumn(char nameOfTable[]);
// Creates a column

int listValues(char nameOfTable[]);
// List all values of an table

int tableExists(char nameOfTable[]);
// Try to open table to check if table exists

int removeTable(char nameOfTable[]);
// Delete a table with the following format tables/nameOfTable.txt

int primaryKeyExists(char nameOfTable[] , int primaryKey);
// Returns 1 if the id already exists, 0 if doesn't or any error occurs

int createLine(char nameOfTable[]);
// Inserts a line

int editLine(char nameOfTable[]);
// Edit a choosen line inside

#endif
