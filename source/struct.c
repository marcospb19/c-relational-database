#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "struct.h"
#include "tables.h"


// Free all the data from a tableStruct
int freeTableStruct(tableStruct_t* tableStruct)
{
	// Above all the free() calls, are the content of the tableStruct that is being freed

	// char[*] primaryKeyName;
	free(tableStruct->primaryKeyName);
	// columnTypes[*] types;
	free(tableStruct->types);

	for (int i = 0 ; i < tableStruct->quantityOfColumns ; i++)
	{
		// char*[*] columnNames;
		free(tableStruct->columnNames[i]);
	}
	// char[*]* columnNames;
	free(tableStruct->columnNames);


	// int quantityOfLines;
	// int quantityOfColumns;
	// char nameOfTable[51];
	free(tableStruct);

	return 0;
}


// Returns a pointer to the tableStruct
tableStruct_t* loadTableStruct(char nameOfTable[])
{
	if (!tableExists(nameOfTable))
	{
		printf("Fail to load, \"%s\" table do not exists.\n", nameOfTable);
		return NULL;
	}

	char* directory = malloc(sizeof(char) * 65); // Maximium size it can get
	sprintf(directory , "tables/%s.txt" , nameOfTable);
	FILE* loadingTable = fopen(directory , "r");
	free(directory);

	// If fails to open or doesn't exists
	if (loadingTable == NULL)
	{
		printf("Fail to load tableStruct\n");
		return NULL;
	}

	tableStruct_t* loadingStruct = malloc(sizeof(tableStruct_t));

	// Now reads the file
	// Read the first 3 lines:

	fscanf(loadingTable, "%s\n%d\n%d\n" ,
	loadingStruct->nameOfTable , // Could use local argument
	&loadingStruct->quantityOfLines ,
	&loadingStruct->quantityOfColumns);

	// Falta preencher ainda
	loadingStruct->types = malloc(sizeof(columnTypes_t) * loadingStruct->quantityOfColumns);

	int position = ftell(loadingTable);
	fscanf(loadingTable , "primary %*[^|]|");
	
	loadingStruct->primaryKeyName = malloc(sizeof(char) * ftell(loadingTable) - position - 9);
	fseek(loadingTable , position , SEEK_SET);
	fscanf(loadingTable , "primary %[^|]|" , loadingStruct->primaryKeyName);

	loadingStruct->columnNames = malloc(sizeof(char*) * loadingStruct->quantityOfColumns);
	// Verifies is error happens, and fills everything to use the free function
	bool typeReadError = false;

	char* typeAux = malloc(sizeof(char) * 10);
	for (int i = 0; i < loadingStruct->quantityOfColumns; i++)
	{
		position = ftell(loadingTable);
		fscanf(loadingTable , "%*s");
		
		loadingStruct->primaryKeyName = malloc(sizeof(char) * ftell(loadingTable) - position);
		fseek(loadingTable , position , SEEK_SET);
		fscanf(loadingTable , "%s" , typeAux);
		
		if (typeReadError)
			loadingStruct->types[i] = 0;
		else if (strcmp(typeAux , "int"	)	== 0)
			loadingStruct->types[i] = int_;
		else if (strcmp(typeAux , "string")	== 0)
			loadingStruct->types[i] = string_;
		else if (strcmp(typeAux , "char")	== 0)
			loadingStruct->types[i] = char_;
		else if (strcmp(typeAux , "float") 	== 0)
			loadingStruct->types[i] = float_;
		else if (strcmp(typeAux , "bool")	== 0)
			loadingStruct->types[i] = bool_;
		else
		{ 
			typeReadError = true;
			printf("Error loading this table, aborting this process\n");
		}

		position = ftell(loadingTable);
		fscanf(loadingTable , " %*[^|]|");

		loadingStruct->columnNames[i] = malloc(sizeof(char) * ftell(loadingTable) - position);
		fseek(loadingTable , position , SEEK_SET);
		fscanf(loadingTable , " %[^|]|" , loadingStruct->columnNames[i]);
	}
	free(typeAux);	

	// Now that we read the 3 first lines, can read the column types and names
	if (typeReadError)
	{
		freeTableStruct(loadingStruct);
		return NULL;
	}
	return loadingStruct;
}