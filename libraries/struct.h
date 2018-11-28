#ifndef STRUCT_H
#define STRUCT_H

// _t stands for type, because of the typedef
typedef enum cT{int_ , float_ , string_ , char_ , bool_} columnTypes_t ;

typedef struct tS
{
	int quantityOfLines;
	int quantityOfColumns; // Doens't include primaryKey

	char nameOfTable[51]; // 50 is the maximium size

	char* primaryKeyName; // Uses malloc

	char** columnNames; // Uses malloc

	columnTypes_t* types; // Uses malloc
} tableStruct_t ;


int freeTableStruct(tableStruct_t* tableStruct);
// Free all the data from a tableStruct


tableStruct_t* loadTableStruct(char nameOfTable[]);
// Loads all itens of a tableStruct based on the name of the table
// And returns the pointer to it

#endif
