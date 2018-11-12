#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "colors.h"


// Similar to strcmp, but returns 1 if found the command inside of the string
int strcommand(char string[] , char command[])
{
	short stringSize = strlen(string);
	short commandSize = strlen(command);

	if (commandSize > stringSize)
		return 0;

	for (register short i = 0 ; i < commandSize ; i++)
	{
		if (command[i] != string[i])
			return 0;
	}

	return 1;
}


int createTable(char nameOfTable[])
{
	FILE* listOfTables = fopen("tables/listOfTables.txt" , "r+");
	if (listOfTables == NULL)
	{
		puts("ERROR: Fail to open listOfTable.txt.");
		return -1;
	}

	// 50 is the maximium size of a table name
	// format: /tables/(nameOfTable).txt
	char* newTableFile = malloc(sizeof(char) * 62);
	// newTableFile stores the string to create the newTable
	strcpy(newTableFile , "tables/");
	strcat(newTableFile , nameOfTable);
	strcat(newTableFile , ".txt");

	FILE* newTable = fopen(newTableFile , "wr");
	free(newTableFile);

	if (newTable == NULL)
	{
		puts("ERROR: Fail to open the new table.");
		fclose(listOfTables);
		return -2;
	}

	short numberOfTables;
	// Get the numberOfTables and go to the second line
	fscanf(listOfTables , "%hd\n" , &numberOfTables);

	// 50 is the maximium size of a table name
	char* tablesToCompare = malloc(sizeof(char) * 51);

	// This for will check if the table already exists
	for (register short i = 0 ; i < numberOfTables ; i++)
	{
		// Get the table in that line
		fscanf(listOfTables , "%s\n" , tablesToCompare);

		// Check if the table already exists
		if (strcmp(tablesToCompare , nameOfTable) == 0)
		{
			fclose(listOfTables);
			fclose(newTable);
			puts("ERROR: Table already exists.");
			return -3;
		}
	}
	free(tablesToCompare);

	// Writing the new table at the end of listOfTables
	fprintf(listOfTables , "%s\n" , nameOfTable);

	// Increase the numberOfTables by 1
	fseek(listOfTables , 0 , SEEK_SET);
	fprintf(listOfTables , "%05d" ,  numberOfTables + 1);
	fclose(listOfTables);

	fprintf(newTable , "%s\n" , nameOfTable);

	char* tableColumnType = malloc(sizeof(char) * 51);
	char* tableColumnName = malloc(sizeof(char) * 51);

	printf("Type the name of the primary key column (id, for example)\n");
	scanf("%s" , tableColumnName);
	fprintf(newTable , "|primary %s| " , tableColumnName);

	puts("Now, fill the columns:");
	short columnCount = 1;
	while (true)
	{
		puts("Column options: int, string, char, float, bool. (0 to finish)");

		// Goto anchor used to repeat this next input
		columnTypeInput:

		printf("Column Type [%d] -> " , columnCount);
		scanf(" %s" , tableColumnType);

		if (tableColumnType[0] == '0')
		{
			colorBoldCyan();
			puts("Created.");
			colorReset();
			break;
		}

		// If it isn't a valid type, take input again
		if (strcmp(tableColumnType , "int"	 ) &&
		    strcmp(tableColumnType , "string") &&
		    strcmp(tableColumnType , "char"	 ) &&
		    strcmp(tableColumnType , "float" ) &&
		    strcmp(tableColumnType , "bool"	 ) )
		{
			printf("Invalid type, try again\n");
			goto columnTypeInput;
		}

		printf("Column Name [%d] -> " , columnCount);
		scanf(" %s" , tableColumnName);

		if (tableColumnName[0] == '0')
		{
			printf("Canceled \'%s\' column.\n" , tableColumnType);
			break;
		}

		// If the input isn't canceled by the user, register the column
		fprintf(newTable , "|%s %s| " , tableColumnType , tableColumnName);

		colorBoldYellow();
		printf("Column %s (%s) inserted.\n" , tableColumnName , tableColumnType);
		colorReset();

		columnCount++;
	}
	fclose(newTable);
	free(tableColumnType);
	free(tableColumnName);

	// colorBoldCyan();
	// printf("\nTable \'%s\' Created with %d columns\n\n", nameOfTable , columnCount - 1);
	// colorReset();

	return 0;
}


int listTables()
{
	// puts("All tables:");
	FILE* listOfTables = fopen("tables/listOfTables.txt" , "r+");
	if (listOfTables == NULL)
	{
		printf("ERROR: Fail to open listOfTables.txt\n");
		return -1;
	}
	register char* lines = malloc(sizeof(char) * 51);

	short number;
	fscanf(listOfTables , "%hd" , &number);

	for (register short i = 0 ; i < number ; i++)
	{
		fscanf(listOfTables , "%s\n" , lines);
		printf("\t%s\n", lines);
	}
	puts("");

	free(lines);
	fclose(listOfTables);

	return 0;
}


