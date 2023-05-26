#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int metrics(int final_score, float wps, int test_num){
	FILE* results_file = fopen("test_results.csv", "a");
	char* header = "Run,Test Score,Writes Per Second,\n";
	
	if(test_num == 1){
		fprintf(results_file, header);
	}

	fprintf(results_file, "%d", test_num);
	fprintf(results_file, ",");
	fprintf(results_file, "%d", final_score);
	fprintf(results_file, ",");
	fprintf(results_file, "%f", wps);
	fprintf(results_file, ",\n");

	fclose(results_file);	

	return 0;
}
