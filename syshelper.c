#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include "syshelper.h"


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
	    else if (equal_to(input, "joke")){
	    	int joke_count = 0;
		if (joke_count = 0){
			printf("What do you call 8 Hobbits?\n");
			printf("A Hobbyte!\n\n");
			joke_count++;
		}
		else if (joke_count = 1){
			printf("There are 10 types of people in the world - those who understand binary, and those who don't.\n\n");
			joke_count++;
		}
		else if (joke_count = 2){
			printf("A SQL query goes into a bar, walks up to two tables and asks, 'Can I join you?'\n\n");
			joke_count++;
		}
		else if (joke_count = 3){
			printf("Why did the programmer quit his job?\n");
			printf("Because he didn't get arrays!\n\n");
			joke_count++;
		}
		else if (joke_count = 4){
			printf("Why do java programmers have to wear glasses?\n");
			printf("Because they don't C#!\n\n");
			joke_count++;
		}
		else if (joke_count = 5){
			printf("Why did the programmer take so long in the shower?\n");
			printf("Because his shampoo said 'lather, rinse, repeat!'\n\n");
			joke_count++;
		}
		else if (joke_count = 6){
			printf("I'm out of jokes!");
			joke_count = 0;
		}
	    }
	    else if (equal_to(input, "time")|| equal_to(input, "date")){
		  time_t rawtime;
  		  struct tm * timeinfo;
  		  time ( &rawtime );
  		  timeinfo = localtime ( &rawtime );
		  printf("Here is the current time and date:%s", asctime(timeinfo));
	    }
	    else if (equal_to(input, "weather") || equal_to(input, "tempurature") || equal_to(input, "temp")){
		printf("Walk outside and find out!");
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

int shellHelper( int argc, char** argv ) {
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

