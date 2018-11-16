#ifndef LIST_H
#define LIST_H

// Global directory
char* listOfTables_Directory;

// tables/listOfTables.txt functions:

short tableListNumber(short change);
// This function changes the number of tables inside of listOfTables.txt (first line)

short numberOfTables();
// Return the number of tables inside of listOfTables.txt

short tableExists(char nameOfTable[]);
// Returns 1 if the table exists, 0 if it doesn't

short listOfTables_AddTable(char nameOfTable[]);
// Add a table to the bottom of listOfTables.txt

short listOfTables_RemoveTable(char nameOfTable[]);
// Remove a table from listOfTables.txt

#endif
