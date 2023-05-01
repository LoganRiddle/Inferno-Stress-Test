#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

//#define SZ 7500

#include "score.c"
#include "tests.c"


int cleanup(void){
	if (remove(".inferno_test.txt") != 0) {
    		printf("Error: unable to delete test file!\n");
    		exit(EXIT_FAILURE);
  	}

	return 0;
}


int main(void){
	char userin[100];
	system("clear");
	//system("neofetch");

	printf("Welcome to Inferno\n");
	printf("\nChoose which test to run:\n");
	printf("=========================\n");
	printf("a.) (short) \nb.) (normal) \nc.) (extended)\n\n");

	scanf("%s", userin);
	printf("\n");

	if(strcmp(userin, "short") == 0 || strcmp(userin, "a") == 0 || strcmp(userin, "A") == 0){
		short_test();
	}else if(strcmp(userin, "normal") == 0 || strcmp(userin, "b") == 0 || strcmp(userin, "B") == 0){
		normal_test();
	}else if(strcmp(userin, "extended") == 0 || strcmp(userin, "c") == 0 || strcmp(userin, "C") == 0){
		extended_test();
	}else{
		printf("Error: userinput not matching options.");
		exit(EXIT_FAILURE);
	}

	cleanup();

	return 0;
}
