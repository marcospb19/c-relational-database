#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
#include "tables.h"
#include "messages.h"
#include "command.h"
#include "struct.h"


int main()
{
	welcomeMessage();
	char userInput[256];

	while (true)
	{
		input:
		printf("\n»»» ");
		fgets(userInput , 256 , stdin);

		// If the user enters nothing, take input again
		if (userInput[0] == '\n')
			goto input;

		// fgets leave the \n at the end, so we need to replace it
		userInput[strlen(userInput) - 1] = '\0';


		if (command(userInput , "help"))
			helpMessage();
		else if (command(userInput , "exit") || userInput[0] == 'q')
		{
			finishMessage();
			break;
		}
		else if (command(userInput , "license"))
			licenseMessage();
		else if (command(userInput , "credits"))
			creditsMessage();


		else if (command(userInput , "list"))
			listTables();
		else if (command(userInput , "printtable"))
		{
			listTables();
			printf("Type the name of the table to list all values\n»»» ");
			scanf(" %s" , userInput);
			listValues(userInput);
		}
		else if (command(userInput , "search"))
		{
			listTables();
			printf("Type the name of the table\n»»» ");
			scanf(" %s" , userInput);
			searchData(userInput);
		}


		else if (command(userInput , "create"))
		{
			listTables();
			printf("Type the name of the table to create\n»»» ");
			scanf(" %s" , userInput);
			createTable(userInput);
		}
		else if (command(userInput , "line"))
		{
			listTables();
			printf("Type the name of the table to create a line\n»»» ");
			scanf(" %s" , userInput);
			createLine(userInput);
		}
		else if (command(userInput , "column"))
		{
			listTables();
			printf("Type the name of the table to create a column\n»»» ");
			scanf(" %s" , userInput);
			createColumn(userInput);
		}
		else if (command(userInput , "remove"))
		{
			listTables();
			printf("Type the name of the table to remove\n»»» ");
			scanf(" %s" , userInput);
			removeTable(userInput);
		}
		else if (command(userInput , "edit"))
		{
			listTables();
			printf("Type the name of the table to edit a line\n»»» ");
			scanf(" %s" , userInput);
			editLine(userInput);
		}
		else if (command(userInput , "erase"))
		{
			listTables();
			printf("Type the name of the table to erase a line\n»»» ");
			scanf(" %s" , userInput);
			removeData(userInput);
		}

		else // If no command is detected
			noInputMessage();
	}
}
