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

// GUI Functions 
/*void greet(GtkWidget* widget, gpointer data);
void destroy(GtkWidget* widget, gpointer data);
int sub(int argc, char* argv[]);
*/
// Global Variables


int main(int argc, char* argv[]){
	char userin[100];
	char rerun[100];
	char gui[100];
	int length = 0;
	int final_score;
	float wps;

	// Cleans up the terminal 
	/*system("clear");
	
	printf("Launch GUI?(N/y): ");
	scanf("%s", gui);

	if((strcmp(gui, "y") == 0) || (strcmp(gui, "Y") == 0)){
		sub(int argc, char* argv[]);
	} 
	*/
	
	while(1){
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
		
		printf("\nTest Score: %d\n", final_score);

		cleanup();

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
