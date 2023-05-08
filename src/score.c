#include <stdio.h>
#include <stdlib.h>


int score(float wps){    
	int count;

	FILE* test_file = fopen(".inferno_test.txt", "r");	
	
	// Checks if the file exists or fails to open
	if (test_file == NULL) {
    		printf("Error: unable to open file test.txt\n");
    		exit(EXIT_FAILURE);
  	}
	
	// Extract characters from file and store in character c
    	for (char c = getc(test_file); c != EOF; c = getc(test_file)){
        	if (c == '\n'){ // Increment count if this character is newline
            		count = count + 1;
 		}
	}
    	
	fclose(test_file);

	return (int)(wps/count);
}
