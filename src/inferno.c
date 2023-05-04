// Required header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Global Variables 
float test(int length);
int score(float wps);
int cpu_info(void);
int cleanup(void);


int main(void){
	char userin[100];
	int length = 0;
	int final_score;
	float wps;

	// Cleans up the terminal 
	system("clear");
	//system("lscpu");
	//system("cat /proc/cpuinfo | grep processor | wc -l");	

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
		length = 4;
		wps = test(length);
		final_score = score(wps);
	}else if(strcmp(userin, "Normal") == 0 || strcmp(userin, "normal") == 0 || strcmp(userin, "b") == 0 || strcmp(userin, "B") == 0){
		length = 2;
		wps = test(length);
		final_score = score(wps);
	}else if(strcmp(userin, "Extended") == 0 || strcmp(userin, "extended") == 0 || strcmp(userin, "c") == 0 || strcmp(userin, "C") == 0){
		length = 1;
		wps = test(length);
		final_score = score(wps);
	}else{
		printf("Error: userinput not matching options.\nInput detected: %s", userin);
		exit(EXIT_FAILURE);
	}
	
	printf("\nTest Score: %d\n", final_score);

	cleanup();

	return 0;
}
