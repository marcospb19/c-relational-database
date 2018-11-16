#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char listOfTables_Directory[] = "tables/listOfTables.txt";

short listOfTables_Number()
{
	FILE* listOfTables = fopen(listOfTables_Directory , "r");
	if (listOfTables == NULL)
	{
		printf("Error at listOfTables_Number");
		return -1;
	}


	short numTables;
	fscanf(listOfTables , "%hd" , &numTables);
	fclose(listOfTables);
	return numTables;
}


// Changes the number of tables inside of listOfTables.txt
bool listOfTables_ChangeNumber(int change)
{
	FILE* listOfTables = fopen(listOfTables_Directory , "r+");
	if (listOfTables == NULL)
	{
		printf("Error at listOfTables_ChangeNumber");
		return false;
	}

	short numTables;
	fscanf(listOfTables , "%hd" , &numTables);

	// If the new value is negative
	if (numTables + change < 0)
	{
		printf("Error at listOfTables_ChangeNumber");
		return false;
	}

	rewind(listOfTables);
	fprintf(listOfTables, "%05hd", numTables + change);
	fclose(listOfTables);

	return true;
}

// Returns true if the table exists, false if it doesn't
bool listOfTables_TableExists(char nameOfTable[])
{
	FILE* listOfTables = fopen(listOfTables_Directory , "r");
	if (listOfTables == NULL)
	{
		printf("Error at listOfTables_TableExists");
		return false;
	}

	short numTables;
	fscanf(listOfTables , "%hd\n" , &numTables);
	char* tableToCompare = malloc(sizeof(char) * 51);

	// Check each table
	for (int i = 0 ; i < numTables ; i++)
	{
		fscanf(listOfTables , "%s\n" , tableToCompare);
		if (strcmp(tableToCompare , nameOfTable) == 0)
		{
			free(tableToCompare);
			return true;
		}
	}
	fclose(listOfTables);
	free(tableToCompare);

	return false;
}


// Adds a table to the end of listOfTables.txt
short listOfTables_AddTable(char nameOfTable[])
{
	FILE* listOfTables = fopen(listOfTables_Directory , "a");
	if (listOfTables == NULL)
	{
		printf("Error at listOfTables_AddTable");
		return -1;
	}

	fprintf(listOfTables , "%s\n" , nameOfTable);
	fclose(listOfTables);
	return 0;
}

// Remove a table from of listOfTables.txt
short listOfTables_RemoveTable(char nameOfTable[])
{
	FILE* listOfTables = fopen(listOfTables_Directory , "r+");
	if (listOfTables == NULL)
	{
		printf("Error at listOfTables_RemoveTable");
		return -1;
	}

	// If the table don't exists
	if (!listOfTables_TableExists(nameOfTable))
	{
		printf("Table don't exists\n");
		return -2;
	}

	short numTables;
	fscanf(listOfTables , "%hd\n" , &numTables);
	char* tableToCompare = malloc(sizeof(char) * 51);

	// Check each table
	for (int i = 0 ; i < numTables ; i++)
	{
		fscanf(listOfTables , "%s\n" , tableToCompare);
		if (strcmp(tableToCompare , nameOfTable) == 0)
		{
			free(tableToCompare);
			return 1;
		}
	}


	free(tableToCompare);
	return 0;
}

