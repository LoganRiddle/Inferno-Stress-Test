// Required header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <gtk/gtk.h>


// Function deginitions 
float test(int length);
int score(float wps);
//int cpu_info(void);
int cleanup(void);
int ui(void);
int metrics(int final_score, float wps, int test_num);

// GUI Functions 
/*void greet(GtkWidget* widget, gpointer data);
void destroy(GtkWidget* widget, gpointer data);
int sub(int argc, char* argv[]);
*/
// Global Variables


int main(int argc, char* argv[]){
	char userin[100];
	char rerun[100];
	char save[100];
	char gui[100];
	int length = 0;
	int final_score;
	float wps;
	int test_num = 0;

	// Cleans up the terminal 
	/*system("clear");
	
	printf("Launch GUI?(N/y): ");
	scanf("%s", gui);

	if((strcmp(gui, "y") == 0) || (strcmp(gui, "Y") == 0)){
		sub(int argc, char* argv[]);
	}*/
	
	
	// Infinite loop to continue to allow for testing until quick 	
	while(1){
		// User interface function to generate the cool stuff
		ui();

		// Takes user input
		scanf("%s", userin);
		printf("\n");

		// Conditional section to determine what test the user wants to run
		if(strcmp(userin, "Short") == 0 || strcmp(userin, "short") == 0 || strcmp(userin, "a") == 0 || strcmp(userin, "A") == 0){
			length = 5;
			wps = test(length);
			final_score = score(wps);
		}else if(strcmp(userin, "Normal") == 0 || strcmp(userin, "normal") == 0 || strcmp(userin, "b") == 0 || strcmp(userin, "B") == 0){
			length = 3;
			wps = test(length);
			final_score = score(wps);
		}else if(strcmp(userin, "Extended") == 0 || strcmp(userin, "extended") == 0 || strcmp(userin, "c") == 0 || strcmp(userin, "C") == 0){
			length = 1;
			wps = test(length);
			final_score = score(wps);
		}else if(strcmp(userin, "q") == 0 || strcmp(userin, "Q") == 0 || strcmp(userin, "exit") == 0 || strcmp(userin, "Exit") == 0 || strcmp(userin, "quit") == 0 || strcmp(userin, "Quit") == 0){
			printf("Exiting Program!\n");
			break;
		}else{
			printf("Error: user input not matching options.\nInput detected: %s\n", userin);
			exit(EXIT_FAILURE);
		}
		
		// Final score
		printf("\nTest Score: %d\n\n", final_score);

		// Removed test file
		cleanup();

		// Increments test numbe
		test_num += 1;

		// Consent to save resutls of the test
		printf("Would you like to save the results? (y/n): ");
		scanf("%s", save);
		
		// Saving the metrics to the test_results.csv file
		if(strcmp(save, "y") == 0 || strcmp(save, "Y") ==  0 || strcmp(save, "yes") == 0 || strcmp(save, "Yes") == 0){
			metrics(final_score, wps, test_num);
		}else{
			printf("Not saving.\n");
		}

		// Consent to rerun the test
		printf("Run another test? (y/n): ");
		scanf("%s", rerun);
		
		if(strcmp(rerun, "y") == 0 || strcmp(rerun, "Y") ==  0 || strcmp(rerun, "yes") == 0 || strcmp(rerun, "Yes") == 0){
			continue;
		}else{
			printf("Exiting Program!\n");
			break;
		}
	
	}

	return 0;
}
