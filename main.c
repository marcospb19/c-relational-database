#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "libraries/messages.h"
#include "libraries/colors.h"

int main()
{
	welcomeMessage();
	char userInput[50];

	while (true)
	{
		printf("»»» ");
		colorWhite();
		scanf(" %s" , userInput);
		colorReset();

		if (strcmp("help" , userInput) == 0)
			helpMessage();
		else if (strcmp("license" , userInput) == 0)
			licenseMessage();
		else if (strcmp("credits" , userInput) == 0)
			creditsMessage();

		// Quit
		else if (strcmp("exit" , userInput) == 0 || userInput[0] == 'q')
		{
			finishMessage();
			break;
		}
		else
			noInputMessage();
	}
}
