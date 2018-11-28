#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "libraries/list.h"
#include "libraries/tables.h"
#include "libraries/commands.h"
#include "libraries/messages.h"



int main()
{
	welcomeMessage();
	char userInput[256];

	while (true)
	{
		input:
		printf("»»» ");

		fgets(userInput , 256 , stdin);
		// If the user enters nothing, take input again
		if (userInput[0] == '\n')
			goto input;

		// fgets leave the \n at the end, so we need to replace it
		userInput[strlen(userInput) - 1] = '\0';

		if (strcmp(userInput , "help") == 0)
			helpMessage();
		else if (strcmp(userInput , "list") == 0)
			listTables();

		else if (strcmp(userInput , "column") == 0)
		{
			puts("All tables available:\n");
			listTables();
			printf("Type the name of the table to create a column\n»»» ");
			scanf(" %s" , userInput);
			createColumn(userInput);
		}
		else if (strcmp(userInput , "column") == 0)
		{
			puts("All tables available:\n");
			listTables();
			printf("Type the name of the table to create a column\n»»» ");
			scanf(" %s" , userInput);
			listValues(userInput);
		}

		else if (strcmp(userInput , "printall") == 0)
		{
			puts("All tables available:\n");
			listTables();
			printf("Type the name of the table to list all values\n»»» ");
			scanf(" %s" , userInput);
			listValues(userInput);
		}



		else if (strcmp(userInput , "line") == 0)
			createLine(); // createLine don't works yet
		else if (strcmp(userInput , "license") == 0)
			licenseMessage();
		else if (strcmp(userInput , "credits") == 0)
			creditsMessage();

		// strcommand return 0 if "create" is at the start of the input.
		else if (strcommand(userInput , "create"))
		{
			printf("Type the name of the table\n»»» ");
			scanf(" %s" , userInput);
			createTable(userInput);
		}

		else if (strcommand(userInput , "search"))
		{
			printf("All tables:\n");
			listTables();
			printf("Type the name of the table\n»»» ");
			scanf(" %s" , userInput);
			searchData(userInput);
		}

		// Quit
		else if (strcmp(userInput , "exit") == 0 ||
		         userInput[0] == 'q')
		{
			finishMessage();
			break;
		}

		// If no command is detected
		else
			noInputMessage();

		puts("");
	}
}
