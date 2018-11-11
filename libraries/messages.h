#ifndef MESSAGES_H
#define MESSAGES_H
#include "messages.c"
#endif

// messages.c contain functions to print messages in the terminal


void welcomeMessage();
// Print welcome message, with 'help', 'credits' and 'license' suggestions

void helpMessage();
// Lists all the commands currently available

void creditsMessage();
// List the creators and official online repository

void licenseMessage();
// Explain in short the license, and print link to the full version

void finishMessage();
// Message printed when the user finished the application correctly

void noInputMessage();
//Prints message if input is invalid
