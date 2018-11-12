#include <stdio.h>
#include "colors.h"

void welcomeMessage()
{
	colorBoldWhite();
	printf("SGBD-ITP 0.1.0, ANSI-C");
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
	puts("\" for more information.\n");
}

// Prints the creators of the SGBD and the official repository
void creditsMessage()
{
	colorBoldWhite();
	printf("SGBD 0.1.0-ITP");
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
	puts(" for more information.\n");
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
	printf(", 29 June 2007\nThis License let\'s anyone use, modify and distribute, except to closed source versions.\nRead more on ");
	colorBoldCyan();
	puts("www.gnu.org/licenses/quick-guide-gplv3.html\n");
	colorReset();
}

// Prints all the available commands
void helpMessage()
{
	colorBoldWhite();
	puts("List of commands:");

	colorBoldYellow();
	printf("%13s: " , "create");
	colorReset();
	puts("Create a table.");

	colorBoldYellow();
	printf("%13s: " , "q | exit");
	colorReset();
	puts("Exit the program,");

	colorBoldYellow();
	printf("%13s: " , "help");
	colorReset();
	puts("Show this message,");

	colorBoldYellow();
	printf("%13s: " , "credits");
	colorReset();
	puts("Show the credits,");

	colorBoldYellow();
	printf("%13s: " , "license");
	colorReset();
	puts("Show the license.");

	puts("");
}


// Prints if input is invalid
void noInputMessage()
{
	colorBoldRed();
	puts("Invalid input, please try again.");
	colorReset();
}
