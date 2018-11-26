#ifndef TABLES_H
#define TABLES_H


typedef enum columnTypes columnTypes;
typedef struct tableStruct tableStruct;

int searchData(char nameOfTable[]);
// Search for data inside of a choosen table

int createTable(char nameOfTable[]);
// Creates tables that can store integers, decimal numbers, characters and strings
// First adds the table to the listOfTables.txt, and then creates the table

int createLine();
// Inserts a line

int loadTableStruct(char nameOfTable[]);
// Fills the struct tableStruct with all the data

int freeTableStruct(tableStruct* pointerFree);
// Free all the data from struct tableStruct

int createColumn(char nameOfTable[]);
// Creates a column

int listValues(char nameOfTable[]);
// List all values of an table

#endif
