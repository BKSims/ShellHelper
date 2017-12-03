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

			if ( tolower( (*b_str1)) != tolower((*b_str2)) ) {

				return FALSE;

			}

			b_str1++;
			b_str2++;

		}

	} 

	return TRUE;
}

int parsing(char* line, int exit) {

	char* str = line;
    tolower( (*str));
    char *input = strtok(str, " ");
    
    int cnt = 0;
    int target = -1; //-1: Nothing, 0: Open, 1: Find
    int response = 0;

    char find[200] = "find ~ -name ";
    char open[200] = "firefox ";

    printf("\nCodey: ");
    // NOTHING ENTERED
    if(input == NULL){
        printf("Did you say something?\n\n");
    }
    else{
        while(input != NULL){
            //FIND WAS PREVIOUS WORD (FIND INPUT)
            if(target == 1){
                strcat(find,input);
                system(find);  // MAKE METHOD LATER
                printf("\n");
                target = -1;
            }
            //OPEN WAS PREVIOUS WORD (OPEN INPUT)
            else if(target == 0){
                strcat(open,input);
                system(open);  // MAKE METHOD LATER
                printf("\n");
                target = -1;
            }
            // WORD IS BYE. EXIT HELPER.
            if (equal_to(input, "bye") || equal_to(input, "exit")) {
                printf("Good bye!\n\n");
                response = 1;
                return exit = TRUE;
            } 
            // WORD IS THANKS. BE POLITE.
            else if (equal_to(input, "thanks") || equal_to(input, "thank")) {
                printf("You're welcome!\n\n");
                response = 1;
            } 
            // WORD IS GREETING. SAY HELLO.
            else if(equal_to(input, "hello") || equal_to(input, "hi") || equal_to(input, "hey")){
                printf("Hello!\n\n");
                response = 1;
            }
            // WORD IS FIND. LOOK AT NEXT WORD.
            else if (equal_to(input, "find")) {
                printf("Okay. One moment please...\n\n");
                response = 1;
                target = 1;
            }
            // WORD IS OPEN. LOOK AT NEXT WORD.
            else if (equal_to(input, "open")) {
                response = 1;
                target = 0;
                printf("There you go!\n");
            }
            //WORD IS JOKE. CHOOSE RANDOM JOKE.
	        else if (equal_to(input, "joke")){
                response = 1;
                time_t t;
                srand((unsigned)time(&t));
                int joke_count = rand() % 6;

		        if (joke_count == 0){
			        printf("What do you call 8 Hobbits?\n");
			        printf("A Hobbyte!\n\n");
		        }
		        else if (joke_count == 1){
			        printf("There are 10 types of people in the world - those who understand binary, and those who don't.\n\n");
		        }
		        else if (joke_count == 2){
			        printf("A SQL query goes into a bar, walks up to two tables and asks, 'Can I join you?'\n\n");
		        }
		        else if (joke_count == 3){
			        printf("Why did the programmer quit his job?\n");
			        printf("Because he didn't get arrays!\n\n");
		        }
		        else if (joke_count == 4){
			        printf("Why do java programmers have to wear glasses?\n");
			        printf("Because they don't C#!\n\n");
		        }
		        else if (joke_count == 5){
			        printf("Why did the programmer take so long in the shower?\n");
			        printf("Because his shampoo said 'lather, rinse, repeat!'\n\n");
		        }
	        }
            //WORD IS TIME OR DATE. GIVE BACK TIME.
            else if (equal_to(input, "time") || equal_to(input, "date")){
                response = 1;
	            time_t rawtime;
      		    struct tm * timeinfo;
      		    time ( &rawtime );
      		    timeinfo = localtime ( &rawtime );
	            printf("Here is the current time and date: %s\n", asctime(timeinfo));
            }
	    //WORD IS FOOD
	    else if(equal_to(input, "food")){
		response = 1;
		printf("I don't know what food tastes like, but I wish I could take a byte!\n\n");
	    }
	    //WORD IS WATER
	    else if(equal_to(input, "water")){
		response = 1;
		printf("I've heard it's important to stay hydrated.\n\n"); 	       
	        printf("I would drink some, but I might short circuit!\n\n");
	    }
	    //WORD IS BAYLEE OR SAVANNAH. THE CREATORS!
	    else if(equal_to(input, "baylee") || equal_to(input, "savannah")){
		response = 1;
		printf("That's one of my creators!\n\n");
	    }
            //WORD IS WEATHER OR TEMPERATURE. BE HELPFUL.
            else if (equal_to(input, "weather") || equal_to(input, "temperature") || equal_to(input, "temp")){
	            printf("Here is MSN's weather report.\n\n");
                response = 1;
                system("firefox https://www.msn.com/en-us/weather");
            }
            // NEXT WORD
            input = strtok(NULL," \0");
        }
        // NO MATCH
        if(response == 0){
            printf("I'm sorry. I didn't understand that...\n\n");
        }
    }
    return exit = FALSE;
}

int shellHelper( int argc, char** argv ) {
    int done = FALSE;
    char input[100];

    printf("\n***NO PUNCTUATION PLEASE***\n");
    printf("\nCodey: Hello! What can I do for you?\n\n");

    while(done == FALSE){
        printf("Helper-Converse$> ");
        gets(input);
        done = parsing(input,done);
    }
    return 0;
}
