#ifndef LIST_H
#define LIST_H

// Global directory
char* listOfTables_Directory;

// tables/listOfTables.txt functions:

int listTables();
// List all the tables inside of listOfTables.txt

int listOfTables_TableListNumber(int change);
// This function changes the number of tables inside of listOfTables.txt (first line)

int listOfTables_NumberOfTables();
// Return the number of tables inside of listOfTables.txt

int listOfTables_AddTable(char nameOfTable[]);
// Add a table to the bottom of listOfTables.txt

int listOfTables_RemoveTable(char nameOfTable[]);
// Remove a table from listOfTables.txt

#endif
