#include <stdio.h>
#include <stdlib.h>


int ui(void){
	system("clear");

	// Builds terminal interface with 	
	printf("Welcome to Inferno\n==================\n\n");
	system("grep -m 1 'model name' /proc/cpuinfo");
	printf("\nChoose which test to run:\n");
	printf("=========================\n");
	printf("a.) (short) \nb.) (normal) \nc.) (extended)\nq.) (quit)\n\n ");	

	return 0;
}
