// Required header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>


// Function deginitions 
float test(int length);
int score(float wps);
int cpu_info(void);
int cleanup(void);

// GUI Functions 
void greet(GtkWidget* widget, gpointer data);
void destroy(GtkWidget* widget, gpointer data);
int sub(int argc, char* argv[]);

// Global Variables


int main(int argc, char* argv[]){
	char userin[100];
	char gui[100];
	int length = 0;
	int final_score;
	float wps;

	// Cleans up the terminal 
	system("clear");
	
	printf("Launch GUI?(N/y): ");
	scanf("%s", gui);

	if((strcmp(gui, "y") == 0) || (strcmp(gui, "Y") == 0)){
		sub(int argc, char* argv[]);
	} 
	
	system("clear");

	// Builds terminal interface with 	
	printf("Welcome to Inferno\n");
	printf("\nChoose which test to run:\n");
	printf("=========================\n");
	printf("a.) (short) \nb.) (normal) \nc.) (extended)\n\n");

	// Takes user input
	scanf("%s", userin);
	printf("\n");

	// Conditional section to determine what test the user wants to run
	if(strcmp(userin, "Short") == 0 || strcmp(userin, "short") == 0 || strcmp(userin, "a") == 0 || strcmp(userin, "A") == 0){
		length = 5;
		wps = test(length);
		final_score = score(wps);
	}else if(strcmp(userin, "Normal") == 0 || strcmp(userin, "normal") == 0 || strcmp(userin, "b") == 0 || strcmp(userin, "B") == 0){
		length = 3;
		wps = test(length);
		final_score = score(wps);
	}else if(strcmp(userin, "Extended") == 0 || strcmp(userin, "extended") == 0 || strcmp(userin, "c") == 0 || strcmp(userin, "C") == 0){
		length = 1;
		wps = test(length);
		final_score = score(wps);
	}else{
		printf("Error: user input not matching options.\nInput detected: %s", userin);
		exit(EXIT_FAILURE);
	}
	
	printf("\nTest Score: %d\n", final_score);

	cleanup();

	return 0;
}
