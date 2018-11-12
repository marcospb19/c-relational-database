#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "libraries/messages.h"
#include "libraries/colors.h"
#include "libraries/tables.h"


int main()
{
	welcomeMessage();
	char userInput[50];

	while (true)
	{
		printf("»»» ");
		scanf(" %s" , userInput);

		if (strcmp(userInput , "help") == 0)
			helpMessage();
		else if (strcmp(userInput , "license") == 0)
			licenseMessage();
		else if (strcmp(userInput , "credits") == 0)
			creditsMessage();

		// This function return 0 if create is at the start of the input
		else if (strcommand(userInput , "create"))
		{
			printf("Type the name of the table\n");
			scanf(" %s" , userInput);
			createTable(userInput);
		}
		else if (strcmp(userInput , "list") == 0)
			listTables();

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
	}
}
