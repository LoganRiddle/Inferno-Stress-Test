#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int metrics(int final_score, float wps, int test_num){
	FILE* results_file = fopen("test_results.csv", "a");
	char data[100]; 
	char* header = "Run,Test Score,Writes Per Second,\n";
	
	/*strcat(data, itoa(test_num));
	strcat(data, ",");
	strcat(data, itoa(final_score));
	strcat(data, ",");
	strcat(data, ftoa(wps));
	strcat(data, ",\n"); 
	*/
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
