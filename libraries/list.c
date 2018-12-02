#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tables.h"
#include "colors.h"

char listOfTables_Directory[] = "tables/listOfTables.txt";

int listTables()
{
	FILE* listOfTables = fopen(listOfTables_Directory , "r+");
	if (listOfTables == NULL)
	{
		printf("ERROR: Fail to open listOfTables.txt\n");
		return -1;
	}
	char* lines = malloc(sizeof(char) * 51);

	// Gets the number of tables to read and jump a line
	int number;
	fscanf(listOfTables , "%d\n" , &number);

	colorBoldWhite();
	puts(" All tables available:\n");
	colorReset();
	for (int i = 0 ; i < number ; i++)
	{
		fscanf(listOfTables , "%[^\n]\n" , lines);
		printf("   %s\n", lines);
	}

	free(lines);
	fclose(listOfTables);

	return 0;
}


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
		printf("Error at listOfTables_ChangeNumber, negative number");
		return 0;
	}

	fseek(listOfTables , 0 , SEEK_SET);
	fprintf(listOfTables, "%05hd", numTables + change);
	fclose(listOfTables);

	return 1;
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



// Remove a table from listOfTables.txt
int listOfTables_RemoveTable(char nameOfTable[])
{
	FILE* listOfTables = fopen(listOfTables_Directory , "r");
	if (listOfTables == NULL)
	{
		printf("Error at listOfTables_RemoveTable\n");
		return -1;
	}
	FILE* NewList = fopen("listOfTables.swp" , "wr+");
	if (NewList == NULL)
	{
		fclose(listOfTables);
		printf("Error: trying to open newList\n");
		return -2;
	}

	// Gets the number of tables and writes at the top of the new table
	int numberOfTables = listOfTables_Number();
	fprintf(NewList , "%05d\n" , numberOfTables);

	// Skips 1 line on listOfTables
	fscanf(listOfTables , "%*[^\n]\n");

	char* aux = malloc(sizeof(char) * 51);
	int i;
	for (i = 0 ; i < numberOfTables ; i++)
	{
		fscanf(listOfTables , "%[^\n]\n" , aux);
		if (strcmp(nameOfTable , aux) != 0)
			fprintf(NewList , "%s\n" , aux);
	}
	free(aux);

	fclose(listOfTables);
	fclose(NewList);

	copyAndPaste("listOfTables.swp" , listOfTables_Directory , numberOfTables);

	// Decreases 1 from the total
	listOfTables_ChangeNumber(-1);
	return 0;
}

