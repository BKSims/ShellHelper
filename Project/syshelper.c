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

void parse( char* line, command_t* p_cmd ) {
//NEED TO CLEAR COMMAND AFTER EVERY USE
    //lower case here
    char *start = strtok(line, " ");
    char *rest = "";
    
    int cnt = 0;
    int target = -1;
    int done = 0;
    
    if(start == NULL){
        p_cmd->argc = 0;
    }
    else{  
        strcpy(p_cmd->argv[cnt],start);
        cnt++;
        //check if one of two commands (if so, add to path)
        if(equal_to(start, "find")){
            strcpy(p_cmd->path,start);
            target = cnt;
        }
        
        while(rest != NULL){
            rest = strtok(NULL," \0");
            if(rest != NULL){
                strcpy(p_cmd->argv[cnt],rest);
                cnt++;
                //printf("%s\n", rest);
                //check if one of two commands (if so, add to path)
                if(equal_to(rest, "find")){
                    strcpy(p_cmd->path,rest);
                    target = cnt;
                }
            }
        }
        
        p_cmd->argc = cnt;
        printf("Path: [%s], Argc: [%d] Target: [%d]\n",p_cmd->path,p_cmd->argc,target);
    }
}

int main( int argc, char** argv ) {
    int done = FALSE;
    int i = 0;
    char input[100];
	command_t command;

	command.path = malloc(sizeof(char)*100);
	command.argv = malloc(sizeof(char*)*50);
    for ( i=0; i<50; i++ ) command.argv[i] = malloc(sizeof(char)*100);

    printf("\nHello! What can I do for you?\n\n");
    while(!done){
        printf("Helper-Converse$> ");
        gets(input);
        parse(input, &command);
        //printf("");
        //free command;
    }
}

