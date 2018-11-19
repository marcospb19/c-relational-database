#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Directory to acess with the main on the root:
char listOfTables_Directory[] = "tables/listOfTables.txt";

int listOfTables_Number() // Return the number of tables in listOfTables.txt
{
	FILE* listOfTables = fopen(listOfTables_Directory , "r");
	if (listOfTables == NULL)
	{
		printf("Error at listOfTables_Number");
		return -1;
	}

	int numTables;
	fscanf(listOfTables , "%d" , &numTables);
	fclose(listOfTables);
	return numTables;
}


// Changes the number of tables inside of listOfTables.txt, returns 1 if sucess
int listOfTables_ChangeNumber(int change)
{
	FILE* listOfTables = fopen(listOfTables_Directory , "r+");
	if (listOfTables == NULL)
	{
		printf("Error at listOfTables_ChangeNumber");
		return 0;
	}

	int numTables;
	fscanf(listOfTables , "%d" , &numTables);

	// If the new value is negative
	if (numTables + change < 0)
	{
		printf("Error at listOfTables_ChangeNumber");
		return 0;
	}

	rewind(listOfTables);
	fprintf(listOfTables, "%05hd", numTables + change);
	fclose(listOfTables);

	return 1;
}

// Returns 1 if the table exists, 0 if it doesn't
int listOfTables_TableExists(char nameOfTable[])
{
	FILE* listOfTables = fopen(listOfTables_Directory , "r");
	if (listOfTables == NULL)
	{
		printf("Error at listOfTables_TableExists");
		return 0;
	}

	int numTables;
	fscanf(listOfTables , "%d\n" , &numTables);
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
	fclose(listOfTables);
	free(tableToCompare);

	return 0;
}


// Adds a table to the end of listOfTables.txt
int listOfTables_AddTable(char nameOfTable[])
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

// // DONT WORK
// // Remove a table from of listOfTables.txt
// int listOfTables_RemoveTable(char nameOfTable[])
// {
// 	FILE* listOfTables = fopen(listOfTables_Directory , "r+");
// 	if (listOfTables == NULL)
// 	{
// 		printf("Error at listOfTables_RemoveTable");
// 		return -1;
// 	}

// 	// If the table don't exists

// 	if (listOfTables_TableExists(nameOfTable))
// 	{
// 		printf("Table don't exists\n");
// 		return -2;
// 	}

// 	int numTables;
// 	fscanf(listOfTables , "%d\n" , &numTables);
// 	char* tableToCompare = malloc(sizeof(char) * 51);

// 	// Check each table
// 	for (int i = 0 ; i < numTables ; i++)
// 	{
// 		fscanf(listOfTables , "%s\n" , tableToCompare);
// 		if (strcmp(tableToCompare , nameOfTable) == 0)
// 		{
// 			free(tableToCompare);
// 			return 1;
// 		}
// 	}


// 	free(tableToCompare);
// 	return 0;
// }

