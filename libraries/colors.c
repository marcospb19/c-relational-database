#include <stdio.h>

// Reset the font color, if changed
void colorReset(){
	printf("\033[0m");}


// High intensity colored
void colorBlack(){
	printf("\033[0;90m");}
void colorRed(){
	printf("\033[0;91m");}
void colorGreen(){
	printf("\033[0;92m");}
void colorYellow(){
	printf("\033[0;93m");}
void colorBlue(){
	printf("\033[0;94m");}
void colorPurple(){
	printf("\033[0;95m");}
void colorCyan(){
	printf("\033[0;96m");}
void colorWhite(){
	printf("\033[0;97m");}


// Bold, and high intensity colored
void colorBoldBlack(){
	printf("\033[1;90m");}
void colorBoldRed(){
	printf("\033[1;91m");}
void colorBoldGreen(){
	printf("\033[1;92m");}
void colorBoldYellow(){
	printf("\033[1;93m");}
void colorBoldBlue(){
	printf("\033[1;94m");}
void colorBoldPurple(){
	printf("\033[1;95m");}
void colorBoldCyan(){
	printf("\033[1;96m");}
void colorBoldWhite(){
	printf("\033[1;97m");}
