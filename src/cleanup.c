// Required header files
#include <stdio.h>
#include <stdlib.h>


// Deletes the temp file used for testing
int cleanup(void){
	// Checks to make sure file is deleted properly
	if(remove("/tmp/.inferno_test.txt") != 0){
		printf("Error: Unable to open test file\n");
		exit(EXIT_FAILURE);
	}
    		
	return 0;
}

