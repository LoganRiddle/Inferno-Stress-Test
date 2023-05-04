#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define SZ 7500

// Global Variables
float A[SZ][SZ];


int test(int length){	
	time_t start, current;
	time(&start);

	int temp;
 	size_t temp_size = sizeof(temp);

	int i, j, count;
	float wps;
	double elapsed;
	FILE* test_file = fopen(".inferno_test.txt", "w");
	char str[100];
	int test_length = 0;

	if (test_file == NULL) {
    		printf("Error: unable to open file test.txt\n");
    		exit(EXIT_FAILURE);
  	}

	if(length == 1){
		test_length = SZ;
	}else if(length == 2){
		test_length = SZ/2;
	}else if(length == 4){
		test_length = SZ/4;
	}else{
		exit(EXIT_FAILURE);
	}

	for(i = 0; i < test_length; i++) {
       		for(j = 0; j < test_length; j++) {
          		A[i][j] = i*j;
       		}
	}

	for(i = 0; i < test_length; i++) {
       		for(j = 1; j < test_length; j++) {
          		A[i][j] = ( A[i][j-1] + A[i][j] ) / 2;
  			time(&current);

    			// Calculate the elapsed time in seconds
   			elapsed = difftime(current, start);
			
			wps = count/elapsed;

    			// Print the elapsed time
    			printf("Elapsed time: %.0f seconds. Write speed: %.02f writes per second\r", elapsed, wps);
			fflush(stdout);

			sprintf(str, "%f", A[i][j]);
			fprintf(test_file, str);
			count += 1;
       		}
    	}

	double awps = count/elapsed;
	printf("\nAverage Write Speed: %.02f writes per second\n", awps);
	printf("Short Test Ended Successfully\n");

	return 0;
}


int cpu_info(void){
	FILE *cpuinfo = fopen("/proc/cpuinfo", "rb");
	char *arg = 0;
   	size_t size = 0;
   
	while(getdelim(&arg, &size, 0, cpuinfo) != -1){
      		puts(arg);
   	}
   	
	free(arg);
   	fclose(cpuinfo);
  	
	return 0;
}


int cleanup(void){
	if (remove(".inferno_test.txt") != 0) {
    		printf("Error: unable to delete test file!\n");
    		exit(EXIT_FAILURE);
  	}

	return 0;
}


int main(void){
	char userin[100];
	int length = 0;

	system("clear");
	//system("lscpu");
	//system("cat /proc/cpuinfo | grep processor | wc -l");	
	
	printf("Welcome to Inferno\n");
	printf("\nChoose which test to run:\n");
	printf("=========================\n");
	printf("a.) (short) \nb.) (normal) \nc.) (extended)\n\n");

	scanf("%s", userin);
	printf("\n");

	if(strcmp(userin, "short") == 0 || strcmp(userin, "a") == 0 || strcmp(userin, "A") == 0){
		length = 4;
		test(length);
	}else if(strcmp(userin, "normal") == 0 || strcmp(userin, "b") == 0 || strcmp(userin, "B") == 0){
		length = 2;
		test(length);
	}else if(strcmp(userin, "extended") == 0 || strcmp(userin, "c") == 0 || strcmp(userin, "C") == 0){
		length = 1;
		test(length);
	}else{
		printf("Error: userinput not matching options.");
		exit(EXIT_FAILURE);
	}

	cleanup();

	return 0;
}
