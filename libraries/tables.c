#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "colors.h"
#include "list.h"

typedef enum {int_ , float_ , string_ , char_ , bool_} columnTypes ;

typedef struct
{
	int quantityOfLines;
	int quantityOfColumns; // Doens't include primaryKey

	char nameOfTable[51]; // 50 is the maximium size

	char* primaryKeyName; // Uses malloc

	char** columnNames; // Uses malloc

	columnTypes* types; // Uses malloc
} tableStruct ;


int searchData(char nameOfTable[])
{
	if (!listOfTables_TableExists(nameOfTable))
	{
		printf("ERROR: table do not exists.\n");
		return -1;
	};

	char* directoryAuxiliar = malloc(sizeof(char) * 62);
	sprintf(directoryAuxiliar , "tables/%s.txt" , nameOfTable);
	
	tableStruct* structure = loadTableStruct(nameOfTable);
	if (structure == NULL)
	{
		printf("Error loading the structure\n");
		return -2;
	}
	
	FILE* table = fopen(directoryAuxiliar , "r");
	if (table == NULL)
	{
		freeTableStruct(structure);
		printf("ERROR: could not open %s\n" , directoryAuxiliar);
		return -3;
	}

	printf("Opened %s\n" , directoryAuxiliar);
	free(directoryAuxiliar);

	while (1)
	{
		printf("Type the name of the column to search (l to list columns)\n");
		
		for (int i = 0 ; i < structure.quantityOfColumns ; ++i)
		{

		}
	}


	return 0;
}



int createTable(char nameOfTable[])
{
	// If table to be created already exists::
	if (listOfTables_TableExists(nameOfTable))
	{
		puts("ERROR: Table already exists.");
		return -1;
	}

	char* newTableDirectory = malloc(sizeof(char) * 62);
	// newTableDirectory = /tables/(nameOfTable).txt
	sprintf(newTableDirectory , "tables/%s.txt" , nameOfTable);

	FILE* newTable = fopen(newTableDirectory , "wr+");
	if (newTable == NULL)
	{
		puts("ERROR: Fail to open the new table.");
		return -2;
	}
	FILE* listOfTables = fopen("../listOfTables.txt" , "r");
	if (listOfTables == NULL)
	{
		fclose(newTable);
		puts("ERROR: Fail to open list of tables.");
		return -10;
	}
	printf("Directory: %s\n" , newTableDirectory);
	free(newTableDirectory); // Free the directory string

	// Writing the new table at the end of listOfTables
	fprintf(newTable , "%s\n" , nameOfTable);

	// Increase the numberOfTables by 1
	fseek(listOfTables , 0 , SEEK_SET);
	// fprintf(listOfTables , "%05d" ,  numberOfTables + 1);
	fclose(listOfTables);

	fprintf(newTable , "%s\n" , nameOfTable);

	char* tableColumnType = malloc(sizeof(char) * 51);
	char* tableColumnName = malloc(sizeof(char) * 51);

	printf("Type the name of the primary key column (id, for example)\n");
	scanf("%s" , tableColumnName);
	fprintf(newTable , "|primary %s| " , tableColumnName);

	puts("Now, fill the columns:");
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


// Returns a pointer to the tableStruct
tableStruct* loadTableStruct(char nameOfTable[])
{
	if (!listOfTables_TableExists(nameOfTable))
	{
		printf("Fail to load, \"%s\" table do not exists.\n", nameOfTable);
		return NULL;
	}

	char* directory = malloc(sizeof(char) * 65); // Maximium size it can get
	sprintf(directory , "tables/%s.txt" , nameOfTable);
	FILE* loadingTable = fopen(directory , "r");
	free(directory);

	// If fails to open or don't exists
	if (loadingTable == NULL)
	{
		printf("Fail to load tableStruct\n");
		return NULL;
	}

	tableStruct* loadingStruct = malloc(sizeof(tableStruct));

	// Now reads the file
	// Read the first 3 lines:

	fscanf(loadingTable, "%s\n%d\n%d\n" ,
	loadingStruct->nameOfTable , // Could use local argument
	&loadingStruct->quantityOfLines ,
	&loadingStruct->quantityOfColumns);

	// Falta preencher ainda
	loadingStruct->types = malloc(sizeof(columnTypes) * loadingStruct->quantityOfColumns);

	int position = ftell(loadingTable);
	fscanf(loadingTable , "primary %*s|");
	
	loadingStruct->primaryKeyName = malloc(sizeof(char) * ftell(loadingTable) - position - 9);
	fseek(loadingTable , position , SEEK_SET);
	fscanf(loadingTable , "primary %[^|]|" , loadingStruct->primaryKeyName);

	loadingStruct->columnNames = malloc(sizeof(char*) * loadingStruct->quantityOfColumns);
	// Verifies is error happens, and fills everything to use the free function
	bool typeError = false;

	char* typeAux = malloc(sizeof(char) * 10);
	for (int i = 0; i < loadingStruct->quantityOfColumns; i++)
	{
		position = ftell(loadingTable);
		fscanf(loadingTable , "%*s");
		loadingStruct->primaryKeyName = malloc(sizeof(char) * ftell(loadingTable) - position);
		fseek(loadingTable , position , SEEK_SET);
		fscanf(loadingTable , "%s" , typeAux);
		
		if (typeError)
			loadingStruct->types[i] = 0;
		else if strcmp(typeAux , "int"	) 
			loadingStruct->types[i] = int_;
		else if strcmp(typeAux , "string")
			loadingStruct->types[i] = string_;
		else if strcmp(typeAux , "char"	 )
			loadingStruct->types[i] = char_;
		else if strcmp(typeAux , "float" )
			loadingStruct->types[i] = float_;
		else if strcmp(typeAux , "bool"	 )
			loadingStruct->types[i] = bool_;
		else
		{ 
			typeError = true;
			printf("Error loading this table\n");
			return NULL;
		}

		position = ftell(loadingTable);
		fscanf(loadingTable , "%*s");

		loadingStruct->columnNames[i] = malloc(sizeof(char) * ftell(loadingTable) - position);
		fseek(loadingTable , position , SEEK_SET);
		fscanf(loadingTable , "%s" , loadingStruct->columnNames[i]); TA ERRADO TEM QUE SER COLUMNTYPES COM TYPEDEF


	}
	free(typeAux);	

	// Now that we read the 3 first lines, can read the column types and names
	return loadingStruct;
}

// Free all the data from a tableStruct
int freeTableStruct(tableStruct* structure)
{
	// Above all the free() calls, are the content of the structure that is being freed

	// char[*] primaryKeyName;
	free(structure->primaryKeyName);
	// columnTypes[*] types;
	free(structure->types);

	for (int i = 0 ; i < structure->quantityOfColumns ; i++)
	{
		// char*[*] columnNames;
		free(structure->columnNames[i]);
	}
	// char[*]* columnNames;
	free(structure->columnNames);


	// int quantityOfLines;
	// int quantityOfColumns;
	// char nameOfTable[51];
	free(structure);

	return 0;
}


int createColumn(char nameOfTable[])
{

	// listTables();
	if (!listOfTables_TableExists(nameOfTable))
	{
		printf("Table don't exists.\n");
		return -1;
	}

	tableStruct* table = loadTableStruct(nameOfTable);
	if (table == NULL)
	{
		printf("Error loading struct\n");
		return -2;
	}

	char* tableToEditDirectory = malloc(sizeof(char) * 62);
	sprintf(tableToEditDirectory , "tables/%s.txt" , nameOfTable);
	FILE* tableToEdit = fopen(tableToEditDirectory , "r");

	if (tableToEdit == NULL)
	{
		printf("Error opening table\n");
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

	// aux = primary id|int idade|string nomes|char sexo|
	// Now check if the column already exists

	// char columnsToCompare[64];





	char* tableColumnName = malloc(sizeof(char) * 51);
	printf("Especify the name of the column:\n");
	scanf(" %s", tableColumnName);



	// Starts filling the swapFile
	fprintf(swapFile , "%s\n%05d\n%05d\n" , table->nameOfTable , table->quantityOfLines , table->quantityOfColumns + 1);


	// Write all the existing columns in 'aux' and the new one from input
	fprintf(swapFile, "%s%s %s|\n", aux , tableColumnType , tableColumnName);

	for (int i = 0 ; i < table->quantityOfLines ; i++)
	{
		// Reads the line, and appends the empty new column
		fscanf(tableToEdit , "%[^\n]\n" , aux);
		fprintf(swapFile, "%s(nil)|\n", aux);
	}

	fclose(tableToEdit);
	fclose(swapFile);

	FILE* copy = fopen("tables/swap.swp" , "r");
	FILE* paste = fopen(tableToEditDirectory , "wr+");
	// Done reading, now replace all

	// 4 is the minimium number of lines inside a table
	for (int i = 0 ; i < 4 + table->quantityOfLines ; i++)
	{
		fscanf(copy , "%[^\n]\n" , aux);
		fprintf(paste , "%s\n" , aux);
	}


	fclose(copy);
	// Cleans the file
	copy = fopen("tables/swap.swp" , "w");
	fclose(copy);

	fclose(paste);

	free(tableToEditDirectory);
	return 0;
}


int listValues(char nameOfTable[])
{
	if (!listOfTables_TableExists(nameOfTable))
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

	tableStruct* table = loadTableStruct(nameOfTable);

	char aux[1024];

	for (int i = 0 ; i < table->quantityOfLines ; i++)
	{
		fscanf(tableFile , "%[^|]|" , aux);
		printf("\n%s", aux);

		for (int j = 0 ; j < table->quantityOfColumns ; j++)
		{
			fscanf(tableFile , "%[^|]|" , aux);
			printf("  |  %s", aux);
		}
		fscanf(tableFile , "\n");
	}
	puts("\n");
	fclose(tableFile);
	free(table);
	return 0;
}
