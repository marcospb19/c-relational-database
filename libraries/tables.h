#ifndef TABLES_H
#define TABLES_H


typedef enum {int_ , float_ , string_ , char_} columnTypes ;

typedef struct
{
	int quantityOfLines;
	int quantityOfColumns; // Doens't include primaryKey

	char nameOfTable[51]; // 50 is the maximium size

	char* primaryKeyName; // Uses malloc

	char** nameOfColumns; // Uses malloc

	columnTypes* types; // Uses malloc
} tableStruct ;


int strcommand(char string[] , char command[]);
// Similar to strcmp, returns 1 if command is inside of the string (instead of returning 0, like strcmp)

int createTable(char nameOfTable[]);
// Creates tables that can store integers, decimal numbers, characters and strings
// First adds the table to the listOfTables.txt, and then creates the table

int listTables();
// List all the tables inside of listOfTables.txt

int createLine();
// Inserts a line

int loadTableStruct(char nameOfTable[]);
// Fills the struct tableStruct with all the data

int freeTableStruct(tableStruct* pointerFree);
// Fills the struct tableStruct with all the data


#endif
