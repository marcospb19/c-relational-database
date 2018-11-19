#include <string.h>

// Checks if the command array is at the start of the string array
int strcommand(char string[] , char command[])
{
	int stringSize = strlen(string);
	int commandSize = strlen(command);

	if (commandSize > stringSize)
		return 0;

	for (register int i = 0 ; i < commandSize ; i++)
	{
		if (command[i] != string[i])
			return 0;
	}

	return 1;
}
