#include <stdio.h>
#include "colors.h"

void welcomeMessage()
{
	colorBoldWhite();
	printf("SGBD-ITP 0.2.2, ANSI-C");
	colorReset();
	printf("\nType \"");
	colorBoldYellow();
	printf("help");
	colorReset();
	printf("\", \"");
	colorBoldYellow();
	printf("credits");
	colorReset();
	printf("\" or \"");
	colorBoldYellow();
	printf("license");
	colorReset();
	printf("\" for more information.\n");
}

// Prints the creators of the SGBD and the official repository
void creditsMessage()
{
	colorBoldWhite();
	printf("SGBD 0.2.2-ITP");
	colorReset();
	printf(" is a software made by ");
	colorBoldWhite();
	printf("João Marcos");
	colorReset();
	printf(" and ");
	colorBoldWhite();
	printf("Guilherme Lira");
	colorReset();
	printf("\nVisit ");
	colorBoldCyan();
	printf("www.github.com/marcospb19/projeto-itp");
	colorReset();
	printf(" for more information.\n");
}

// Message when user quits successfully
void finishMessage()
{
	colorBoldRed();
	puts("Finished successfully.");
	colorReset();
}

// Prints the License applied to all the repository
void licenseMessage()
{
	colorBoldWhite();
	printf("GNU General Public License 3.0");
	colorReset();
	printf("\nRead more on ");
	colorBoldCyan();
	printf("www.gnu.org/licenses/quick-guide-gplv3.html");
	colorReset();
	puts(".");
}

// Prints all the available commands
void helpMessage()
{
	colorBoldWhite();
	puts(" List of commands:\n");

	colorBoldYellow();
	printf("%12s: " , "help");
	colorWhite();
	puts("Show this message,");

	colorBoldYellow();
	printf("%12s: " , "exit|q");
	colorWhite();
	puts("Exit the program,");

	colorBoldYellow();
	printf("%12s: " , "credits");
	colorWhite();
	puts("Show the credits,");

	colorBoldYellow();
	printf("%12s: " , "license");
	colorWhite();
	puts("Show the license.");

	puts("");

	colorBoldYellow();
	printf("%12s: " , "list");
	colorWhite();
	puts("List all tables,");

	colorBoldYellow();
	printf("%12s: " , "printtable");
	colorWhite();
	puts("List all data inside of a table,");

	colorBoldYellow();
	printf("%12s: " , "search");
	colorWhite();
	puts("Search for data inside of a chossen column table.");

	puts("");

	colorBoldYellow();
	printf("%12s: " , "create");
	colorWhite();
	puts("Create a table,");

	colorBoldYellow();
	printf("%12s: " , "line");
	colorWhite();
	puts("Create a line inside of a choosen table,");

	colorBoldYellow();
	printf("%12s: " , "edit");
	colorWhite();
	puts("Edit a line inside of a choosen table,");

	colorBoldYellow();
	printf("%12s: " , "column");
	colorWhite();
	puts("Create a column in a table,");

	colorBoldYellow();
	printf("%12s: " , "remove");
	colorWhite();
	puts("Delete table from the system.");


	colorReset();
}


// Prints if input is invalid
void noInputMessage()
{
	colorBoldRed();
	puts("Invalid input, please try again.");
	colorReset();
}
