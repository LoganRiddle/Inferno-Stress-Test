// Required header files
#include <stdio.h>
#include <stdlib.h>


// Deletes the temp file used for testing
int cleanup(void){
	// Checks to make sure file is deleted properly
	if (remove(".inferno_test.txt") != 0) {
    		printf("Error: unable to delete test file!\n");
    		exit(EXIT_FAILURE);
  	}

	return 0;
}

