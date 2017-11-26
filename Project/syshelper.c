#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"


int equal_to( char* str1, char* str2 ) {
/* ------------------------------------------------------------------------------

This function is used to compare to string values (not case sensitive)
 
function:
	- parameter(s): pointers to string 1 (str1) and string 2 (str2)
	- return: TRUE (1) or FALSE (0)

*/


	// First check length

	int len[] = {0,0};

	char* b_str1 = str1;
	char* b_str2 = str2;

	while( (*str1) != '\0' ) { 
		len[0]++;
		str1++;
	}

	while( (*str2) != '\0' ) {
		len[1]++;
		str2++;
	}

	if ( len[0] != len[1] ) {

		return FALSE;

	} else {

		while ( (*b_str1) != '\0' ) {

			// don't care about case (you did not have to perform
			// this operation in your solution

			if ( tolower( (*b_str1)) != tolower((*b_str2)) ) {

				return FALSE;

			}

			b_str1++;
			b_str2++;

		}

	} 

	return TRUE;
} // end compare function definition

int parsing(char* line, int exit) {

	char* str = line;
    tolower( (*str));
    char *input = strtok(str, " ");
    
    int cnt = 0;
    int target = -1;
    int done = 0;
    int response = 0;

    printf("\nCodey: ");
    if(input == NULL){
        printf("Did you say something?\n\n");
    }
    else{
        while(input != NULL){
            if (equal_to(input, "bye") || equal_to(input, "exit")) {
                printf("Good bye!\n\n");
                response = 1;
                return exit = TRUE;
            } 
            else if(equal_to(input, "hello") || equal_to(input, "hi") || equal_to(input, "hey")){
                printf("Hello!\n\n");
                response = 1;
            }
            else if (equal_to(input, "find")) {
                printf("Found find.\n\n");
                response = 1;
                target = cnt+1;
            }
            cnt++;
            input = strtok(NULL," \0");
        }
        if(response == 0){
            printf("I'm sorry. I didn't understand that...\n\n");
        }
    }
    return exit = FALSE;
}

int main( int argc, char** argv ) {
    int done = FALSE;
    int i = 0;
    char input[100];

    printf("\nNO PUNCTUATION PLEASE.\n\n");
    printf("\nCodey: Hello! What can I do for you?\n\n");

    while(done == FALSE){
        printf("Helper-Converse$> ");
        gets(input);
        done = parsing(input,done);
    }
}

