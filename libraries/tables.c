#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "colors.h"
#include "list.h"
#include "struct.h"


// Returns 1 if the table exists, 0 if it doesn't
int tableExists(char nameOfTable[])
{
	char* tableDirectory = malloc(sizeof(char) * 62);
	sprintf(tableDirectory , "tables/%s.txt" , nameOfTable);

	FILE* table = fopen(tableDirectory , "r");
	free(tableDirectory);
	if (table == NULL)
	{
		return 0; // Table don't exists
	}
	fclose(table);
	return 1;
}


int searchData(char nameOfTable[])
{
	if (!tableExists(nameOfTable))
	{
		printf("ERROR: table do not exists.\n");
		return -1;
	}

	char* directoryAuxiliar = malloc(sizeof(char) * 62);
	sprintf(directoryAuxiliar , "tables/%s.txt" , nameOfTable);

	tableStruct_t* tableStruct = loadTableStruct(nameOfTable);
	if (tableStruct == NULL)
	{
		printf("Error loading the tableStruct\n");
		return -2;
	}

	FILE* table = fopen(directoryAuxiliar , "r");
	if (table == NULL)
	{
		freeTableStruct(tableStruct);
		printf("ERROR: could not open %s\n" , directoryAuxiliar);
		return -3;
	}

	printf("Opened %s\n" , directoryAuxiliar);
	free(directoryAuxiliar);

	printf("CHOOSE A COLUMN TO SEARCH:\n");
	for (int i = 0; i < tableStruct->quantityOfColumns; ++i)
	{
		printf("[ %d ]   %s\n", i , tableStruct->columnNames[i]);
	}

	int searchingValueInt;
	float searchingValueFloat;

	int valueInt;
	float valueFloat;
	char searchInput[52];

	int option;
	bool aditionalOption = false;

	int numberOfColumnToSearch;
	scanf(" %d" , &numberOfColumnToSearch);

	if (tableStruct->types[numberOfColumnToSearch] == int_ ||
		tableStruct->types[numberOfColumnToSearch] == float_)
	{
		aditionalOption = true;
		if (tableStruct->types[numberOfColumnToSearch] == int_)
			printf("Column is int, choose an option\n");
		else
			printf("Column is float, choose an option\n");

		printf("[ 0 ] valores maior que o valor informado\n");
		printf("[ 1 ] valores maior ou igual que o valor informado\n");
		printf("[ 2 ] valores igual o valor informado\n");
		printf("[ 3 ] valores menor que o valor informado\n");
		printf("[ 4 ] valores menor ou igual que o valor informado\n");
		printf("»»» ");
		scanf(" %d" , &option);

		if (tableStruct->types[numberOfColumnToSearch] == int_)
		{
			printf("Type the int value you wanna search: \n");
			scanf(" %d" , &valueInt);
		}
		else
		{
			printf("Type the float value you wanna search: \n");
			scanf(" %f" , &valueFloat);
		}

	}
	else
	{
		printf("Now enter the value you want to search\n");
		scanf(" %s" , searchInput);
	}

	// Skips 4 lines on table file
	fscanf(table , "%*s\n%*d\n%*d\n%*[^\n]\n");

	int positionToStartOfLine , primaryKeyFound;
	bool found;
	bool foundONE = false;
	char aux[200];
	for (int i = 0; i < tableStruct->quantityOfLines; ++i)
	{
		found = false;
		positionToStartOfLine = ftell(table);
		// Skips 1 column (primary key column)
		fscanf(table , "%*[^|]|");
		// Skipps to the desired column

		for (int j = 0; j < numberOfColumnToSearch ; ++j)
		{
			fscanf(table , "%*[^|]|");
		}

		if (aditionalOption == true)
		{
			if (tableStruct->types[numberOfColumnToSearch] == int_)
			{
				fscanf(table , " %d|" , &searchingValueInt);
			}
			else
			{
				fscanf(table , " %f|" , &searchingValueFloat);
			}

			// printf("[ 0 ] valores maiores que o valor informado\n");
			// printf("[ 1 ] valores maiores ou igual que o valor informado\n");
			// printf("[ 2 ] valores iguais o valor informado\n");
			// printf("[ 3 ] valores menores que o valor informado\n");
			// printf("[ 4 ] valores menores ou igual que o valor informado\n");

			if (option == 0)
			{
				if (tableStruct->types[numberOfColumnToSearch] == int_)
				{
					if (searchingValueInt > valueInt)
						found = true;
				}
				else
				{
					if (searchingValueFloat > valueFloat)
						found = true;
				}
			}
			if (option == 1)
			{
				if (tableStruct->types[numberOfColumnToSearch] == int_)
				{
					if (searchingValueInt >= valueInt)
						found = true;
				}
				else
				{
					if (searchingValueFloat >= valueFloat)
						found = true;
				}
			}
			if (option == 2)
			{
				if (tableStruct->types[numberOfColumnToSearch] == int_)
				{
					if (searchingValueInt == valueInt)
						found = true;
				}
				else
				{
					if (searchingValueFloat == valueFloat)
						found = true;
				}
			}
			if (option == 3)
			{
				if (tableStruct->types[numberOfColumnToSearch] == int_)
				{
					if (searchingValueInt <= valueInt)
						found = true;
				}
				else
				{
					if (searchingValueFloat <= valueFloat)
						found = true;
				}
			}
			if (option == 4)
			{
				if (tableStruct->types[numberOfColumnToSearch] == int_)
				{
					if (searchingValueInt < valueInt)
						found = true;
				}
				else
				{
					if (searchingValueFloat < valueFloat)
						found = true;
				}
			}


			if (found == true)
			{
				if (foundONE == false)
				{
					foundONE = true;
					if (tableStruct->types[numberOfColumnToSearch] == int_)
						printf("Found \"%d\"!!!\n" , valueInt);
					else
						printf("Found \"%f\"!!!\n" , valueFloat);
				}


				// Get the primary key
				fseek(table , positionToStartOfLine , SEEK_SET);
				fscanf(table , "%d|" , &primaryKeyFound);

				// Go again to the end
				fseek(table , positionToStartOfLine , SEEK_SET);
				fscanf(table , "%[^\n]\n" , aux);


				printf("Found at line %d, primarykey: %d\n" , i , primaryKeyFound);
				printf("\t\tLine: %s\n" , aux);
			}

		}
		else
		{
			fscanf(table , "%[^|]|" , aux);
		}

		// If the value is found
		// Search process for int and float
		// Search for other types
		if (strcmp(aux , searchInput) == 0)
		{
			foundONE = true;

			// Get the primary key
			fseek(table , positionToStartOfLine , SEEK_SET);
			fscanf(table , "%d|" , &primaryKeyFound);

			// Go again to the end
			fseek(table , positionToStartOfLine , SEEK_SET);
			fscanf(table , "%[^\n]\n" , aux);


			printf("Found at line %d, primarykey: %d\n" , i , primaryKeyFound);
			printf("\t\tLine: %s\n" , aux);
		}
	}


	if (!foundONE)
		printf("Value not found\n");

	freeTableStruct(tableStruct);

	return 0;
}



int createTable(char nameOfTable[])
{
	// If table to be created already exists::
	if (tableExists(nameOfTable))
	{
		puts("ERROR: Table already exists.");
		return -1;
	}

	char* newTableDirectory = malloc(sizeof(char) * 62);
	sprintf(newTableDirectory , "tables/%s.txt" , nameOfTable);
	FILE* newTable = fopen(newTableDirectory , "wr+");
	if (newTable == NULL)
	{
		puts("ERROR: Fail to open the new table.");
		return -2;
	}
	colorBoldYellow();
	printf("Table created at: %s\n" , newTableDirectory);
	colorReset();
	free(newTableDirectory); // Free the directory string

	fprintf(newTable , "%s\n00000\n00000\n" , nameOfTable);

	char* tableColumnType = malloc(sizeof(char) * 51);
	char* tableColumnName = malloc(sizeof(char) * 51);

	printf("Type the name of the primary key column (id, for example)\n");
	scanf("%s" , tableColumnName);
	fprintf(newTable , "primary %s|" , tableColumnName);

	colorBoldYellow();
	puts("Now, fill the columns:");
	colorReset();

	int columnCount = 1;
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
			puts("Table created.");
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
			goto columnTypeInput;
		}

		// If the input isn't canceled by the user, register the column
		fprintf(newTable , "%s %s|" , tableColumnType , tableColumnName);

		colorBoldYellow();
		printf("Column %s (%s) inserted.\n" , tableColumnName , tableColumnType);
		colorReset();

		columnCount++;
	}

	free(tableColumnType);
	free(tableColumnName);

	fseek(newTable , 0 , SEEK_SET);
	fscanf(newTable , "%*[^\n]\n%*d\n");
	fprintf(newTable , "%05d\n" , columnCount - 1);
	fclose(newTable);


	// Adding one to the count inside of listOfTables.txt
	listOfTables_ChangeNumber(1);
	// Writing the new table at the end of listOfTables.txt
	listOfTables_AddTable(nameOfTable);

	return 0;
}


// Not completed?
int createLine()
{
	FILE* listOfTables = fopen("tables/listOfTables.txt" , "r+");
	if (listOfTables == NULL)
	{
		printf("ERROR: Fail to open listOfTables.txt\n");
		return -1;
	}


	printf("Type the name of the table you want to insert a line.\n");
	// 50 is the maximium size of a table name
	char* nameOfTable = malloc(sizeof(char) * 51);
	char* tablesToCompare = malloc(sizeof(char) * 51);
	scanf("%s", nameOfTable);

	int numberOfTables;
	fscanf(listOfTables , "%d\n" , &numberOfTables);

	bool notFound = true;
	// This for will check if the table exists
	for (int i = 0 ; i < numberOfTables ; i++)
	{
		// Get the table in that line
		fscanf(listOfTables , "%s\n" , tablesToCompare);

		// Check if the table already exists
		if (strcmp(tablesToCompare , nameOfTable) == 0)
		{
			char* directoryAuxiliar = malloc(sizeof(char) * 62);
			strcpy(directoryAuxiliar , "tables/");
			strcat(directoryAuxiliar , nameOfTable);
			strcat(directoryAuxiliar , ".txt");

			FILE* tableToChange = fopen(directoryAuxiliar , "r+");
			if (tableToChange == NULL)
				return -2;

			free(directoryAuxiliar);

			fseek(tableToChange , 0 , SEEK_END);

			// char*

			notFound = false;
			break;
		}
	}
	if (notFound) // If table do not exists
		return -3;

	fclose(listOfTables);

	free(tablesToCompare);
	free(nameOfTable);
	return 0;
}



int listValues(char nameOfTable[])
{
	if (!tableExists(nameOfTable))
	{
		printf("Table don't exists.\n");
		return -1;
	}

	char* tableToEditDirectory = malloc(sizeof(char) * 62);
	sprintf(tableToEditDirectory , "tables/%s.txt" , nameOfTable);
	FILE* tableFile = fopen(tableToEditDirectory , "r+");
	free(tableToEditDirectory);

	if (tableFile == NULL)
	{
		printf("Error opening tableFile\n");
		return -2;
	}

	// Skips 4 lines on the reading file
	for (int i = 0 ; i < 4 ; i++)
		fscanf(tableFile , "%*[^\n]\n");

	tableStruct_t* tableStruct = loadTableStruct(nameOfTable);

	char aux[1024];

	for (int i = 0 ; i < tableStruct->quantityOfLines ; i++)
	{
		fscanf(tableFile , "%[^|]|" , aux);
		printf("\n%s", aux);

		for (int j = 0 ; j < tableStruct->quantityOfColumns ; j++)
		{
			fscanf(tableFile , "%[^|]|" , aux);
			printf("  |  %s", aux);
		}
		fscanf(tableFile , "\n");
	}
	puts("\n");
	fclose(tableFile);
	free(tableStruct);
	return 0;
}

// Reads source, replace on destination and clears source
int copyAndPaste(char source[] , char destination[] , int numberOfLines)
{
	FILE* copy = fopen(source , "r");
	FILE* paste = fopen(destination , "w");

	if (copy == NULL || paste == NULL)
	{
		printf("Error trying to copy file into another\n");
		if (copy == NULL)
			fclose(copy);
		if (paste == NULL)
			fclose(paste);
		return -1;
	}

	char* aux = malloc(sizeof(char) * 4096);

	// Copying all lines from copy file to paste file
	for (int i = 0 ; i < numberOfLines ; i++)
	{
		fscanf(copy , "%[^\n]\n" , aux);
		fprintf(paste , "%s\n" , aux);
	}
	fclose(copy);
	fclose(paste);
	free(aux);

	// Cleans the source file
	remove("tables/swap.swp");
	return 0;
}


int createColumn(char nameOfTable[])
{
	// listTables();
	if (!tableExists(nameOfTable))
	{
		printf("Table don't exists.\n");
		return -1;
	}

	tableStruct_t* tableStruct = loadTableStruct(nameOfTable);
	if (tableStruct == NULL)
	{
		printf("Error loading struct\n");
		return -2;
	}

	char* tableToEditDirectory = malloc(sizeof(char) * 62);
	sprintf(tableToEditDirectory , "tables/%s.txt" , nameOfTable);
	FILE* tableToEdit = fopen(tableToEditDirectory , "r");

	if (tableToEdit == NULL)
	{
		printf("Error opening tableStruct\n");
		return -3;
	}

	FILE* swapFile = fopen("tables/swap.swp" , "wr+");
	if (swapFile == NULL)
	{
		printf("Error opening swapFile table\n");
		fclose(tableToEdit);
		return -4;
	}

	char* tableColumnType = malloc(sizeof(char) * 51);

	columnTypeInput1:
	printf("Especify the type of the column:\n");
	scanf(" %s", tableColumnType);

	// If it isn't a valid type, take input again
	if (strcmp(tableColumnType , "int"	 ) &&
		strcmp(tableColumnType , "string") &&
		strcmp(tableColumnType , "char"	 ) &&
		strcmp(tableColumnType , "float" ) &&
		strcmp(tableColumnType , "bool"	 ) )
	{
		printf("Invalid type, try again\n");
		goto columnTypeInput1;
	}

	char aux[2048];

	// Skips 3 lines on the reading file
	for (int i = 0 ; i < 3 ; i++)
		fscanf(tableToEdit , "%*[^\n]\n");

	// Reads the columns that already exists
	fscanf(tableToEdit , "%[^\n]\n" , aux);

	char* tableColumnName = malloc(sizeof(char) * 51);
	printf("Especify the name of the column:\n");
	scanf(" %s", tableColumnName);

	// Starts filling the swapFile
	fprintf(swapFile , "%s\n%05d\n%05d\n" , tableStruct->nameOfTable , tableStruct->quantityOfLines , tableStruct->quantityOfColumns + 1);


	// Write all the existing columns in 'aux' and the new one from input
	fprintf(swapFile, "%s%s %s|\n", aux , tableColumnType , tableColumnName);

	for (int i = 0 ; i < tableStruct->quantityOfLines ; i++)
	{
		// Reads the line, and appends the empty new column
		fscanf(tableToEdit , "%[^\n]\n" , aux);
		fprintf(swapFile, "%s(nil)|\n", aux);
	}

	fclose(tableToEdit);
	fclose(swapFile);

	copyAndPaste("tables/swap.swp" , tableToEditDirectory , 4 + tableStruct->quantityOfLines);

	freeTableStruct(tableStruct);
	free(tableToEditDirectory);
	return 0;
}


int removeTable(char nameOfTable[])
{
	if (!tableExists(nameOfTable))
	{
		printf("Error: table doesn't exists\n");
		return -1;
	}
	char* tableDirectory = malloc(sizeof(char) * 62);
	sprintf(tableDirectory , "tables/%s.txt" , nameOfTable);

	int removeStatus = remove(tableDirectory);

	if (removeStatus == 1)
	{
		printf("Error: Unable to delete %s\n" , nameOfTable);
		free(tableDirectory);
		return -2; // End here
	}
	free(tableDirectory);

	printf("File removed\n");

	// Remove table from listOfTables.txt
	listOfTables_RemoveTable(nameOfTable);

	return 0;
}


// Returns 1 if the id already exists, 0 if doesn't or any error occurs
int idExists(char nameOfTable[] , int primaryKey)
{
	if (!tableExists(nameOfTable))
	{
		printf("Error: this table don't exists\n");
		return 0;
	}

	char* tableDirectory = malloc(sizeof(char) * 62);
	sprintf(tableDirectory , "tables/%s.txt" , nameOfTable);

	FILE* table = fopen(tableDirectory , "r");
	free(tableDirectory);
	if (table == NULL) // Pretty much a redundant error checking
	{
		printf("Error trying to open this table here\n");
		return 0;
	}

	tableStruct_t* tableStruct = loadTableStruct(nameOfTable);

	if (tableStruct == NULL)
	{
		printf("Error trying to load struct here\n");
		fclose(table);
		return 0;
	}
	// Skips the four first lines
	fscanf(table , "%*[^\n]\n%*d\n%*d\n%*[^\n]\n");
	// Maybe wanna go back after, edit, and to grab the name of the primary key column

	int primaryKeyCompare;
	for (int i = 0 ; i < tableStruct->quantityOfLines ; i++)
	{
		// primaryKeyCompare is the key at the start of each line
		fscanf(table , "%d|" , &primaryKeyCompare);
		if (primaryKey == primaryKeyCompare)
		{
			return 1;
		}
		fscanf(table , "%*[^\n]\n");

	}

	freeTableStruct(tableStruct);
	return 0;
}
