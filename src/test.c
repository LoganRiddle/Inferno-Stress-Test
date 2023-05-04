// Required header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Test size macro
#define SZ 7500

// Global Variables
float A[SZ][SZ];


int test(int length){	
	// Local variables 
	time_t start, current;
	time(&start);

	int temp;
 	size_t temp_size = sizeof(temp);

	int i, j, count;
	float wps;
	double elapsed;
	char str[100];
	int test_length = 0;

	// Creates the test file
	FILE* test_file = fopen(".inferno_test.txt", "w");

	// Checks if the file exists or fails to open
	if (test_file == NULL) {
    		printf("Error: unable to open file test.txt\n");
    		exit(EXIT_FAILURE);
  	}

	// Conditional section that determines which test length the user chose
	if(length == 1){
		test_length = SZ/length;
	}else if(length == 2){
		test_length = SZ/length;
	}else if(length == 4){
		test_length = SZ/length;
	}else{
		exit(EXIT_FAILURE);
	}
	
	// Loop to initialize the 2D test array
	for(i = 0; i < test_length; i++) {
       		for(j = 0; j < test_length; j++) {
          		A[i][j] = i*j;
       		}
	}

	for(i = 0; i < test_length; i++) {
       		for(j = 1; j < test_length; j++) {
			// Algorythm to stress the cpu with a 2D array
          		A[i][j] = ( A[i][j-1] + A[i][j] ) / 2;
  			time(&current);

    			// Calculate the elapsed time in seconds
   			elapsed = difftime(current, start);
			
			// Metric for user output
			wps = count/elapsed;

    			// Print the elapsed time
    			printf("Elapsed time: %.0f seconds. Write speed: %.02f writes per second\r", elapsed, wps);
			fflush(stdout);
			
			// Write operation to the test file
			sprintf(str, "%f", A[i][j]);
			fprintf(test_file, str);
			count += 1;
       		}
    	}

	// Pretty output for some different metrics
	double awps = count/elapsed;
	printf("\nAverage Write Speed: %.02f writes per second\n", awps);
	printf("Short Test Ended Successfully\n");

	return 0;
}

