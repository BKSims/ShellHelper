#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include "shell.h"

const char* valid_builtin_commands[] = {"cd", "exit", "helper", NULL};


void parse( char* line, command_t* p_cmd ) {

    char *path = strtok(line, " ");
    char *rest = "";
    
    int cnt = 0;
    
    if(path == NULL){
        p_cmd->argc = 0;
    }
    else{  
        strcpy(p_cmd->argv[cnt],path);
        cnt++;
        
        while(rest != NULL){
            rest = strtok(NULL," \0");
            if(rest != NULL){
                strcpy(p_cmd->argv[cnt],rest);
                cnt++;
            }
        }
        if(find_fullpath(path,p_cmd) != 0){
            strcpy(p_cmd->path,path);
            if(is_builtin( p_cmd ) == FALSE){
                p_cmd->argc = -1;
                return;
            }
        }
        p_cmd->argc = cnt;
    }

} // end parse function


int execute( command_t* p_cmd ) {
	
	// ----------------------------------------
	// TODO: you fully implement this function

	// -------------------------------------------
	// Added a default return statement
	// however this needs to be changed 
	// to reflect the correct return 
	// value described in the header file

    if ( p_cmd->argc > 0 ) {
        if ( fork() == 0 ) {
        // This is the child
        // Execute in same environment as parent
            p_cmd->argv[p_cmd->argc] = NULL;
            execv(p_cmd->path, p_cmd->argv); 
            perror("Execute terminated with an error condition!\n");
            exit(0);
        }
        // This is the parent - wait for the child to terminate
        wait(0);
    } else if ( p_cmd->argc == -1 ) {
        fprintf( stderr, "%s: command not found!\n", p_cmd->path );
    }

	return 0;


} // end execute function


int find_fullpath( char* command_name, command_t* p_cmd ) {
	
	// ----------------------------------------
	// TODO: you fully implement this function


	// -------------------------------------------
	// Added a default return statement
	// however this needs to be changed 
	// to reflect the correct return 
	// value described in the header file

	char* PATH = getenv( "PATH" );

    int size = strlen(PATH);
    int first = 0;

    char folder[size];
    char slash[100] = "/";
    char *comm = strcat(slash, command_name);

    struct stat buffer;
    int exists;

    for(int i = 0; i < strlen(PATH); i++){
        if(PATH[i] != ':'){
            folder[first] = PATH[i];
            first++;
        }
        if(PATH[i] == ':'|| i == (strlen(PATH)-1)){
            strcat(folder, comm);
            exists = stat(folder, &buffer );
            if ( exists == 0 && ( S_IFDIR & buffer.st_mode ) ) {
                // Directory exists
                strcpy(p_cmd->path,folder);
                return 0;
            } else if ( exists == 0 && ( S_IFREG & buffer.st_mode ) ) {
                // File exists
                strcpy(p_cmd->path,folder);
                return 0;
            } else {
                // Not a valid file or directory
                bzero(folder, strlen(PATH));
                first = 0;
            }

        }
    }
    strcpy(p_cmd->path, command_name);

    return 1;

} // end find_fullpath function


int is_builtin( command_t* p_cmd ) {
/* ------------------------------------------------------------------------------

This function will determine if command (cmd for short) entered in the shell by 
the user is a valid builtin command.

HINT(s): Use valid_builtin_commands array defined in shell.c

function:
	- parameter(s): pointer to a command_t structure
	- return: TRUE if the cmd is in array, else FALSE if not in array. 

*/

	int cnt = 0;

	while ( valid_builtin_commands[cnt] != NULL ) {

		if ( equals( p_cmd->path, valid_builtin_commands[cnt] ) ) {

			return TRUE;

		}

		cnt++;

	}

	return FALSE;

} // end is_builtin function


int do_builtin( command_t* p_cmd ) {
/* ------------------------------------------------------------------------------

This function is used execute built-in commands such as change directory (cd)

HINT(s): See man page for more information about chdir function 

function:
	- parameter(s): pointer to a command_t structure
	- return: SUCCESSFUL if no error occurred during chdir operation, or ERROR 
			if an error condition was generated by chdir operation.

*/


	// only builtin command is cd

	if ( DEBUG ) printf("[builtin] (%s,%d)\n", p_cmd->path, p_cmd->argc);

	struct stat buff;
	int status = ERROR;

	if ( p_cmd->argc == 1 ) {

		// -----------------------
		// cd with no arg
		// -----------------------
		// change working directory to that
		// specified in HOME environmental 
		// variable

		status = chdir( getenv("HOME") );

	} 
    else if ( ( stat( p_cmd->argv[1], &buff ) == 0 && ( S_IFDIR & buff.st_mode ) ) ) {


		// -----------------------
		// cd with one arg 
		// -----------------------
		// only perform this operation if the requested
		// folder exists

		status = chdir( p_cmd->argv[1] );

	} 

	return status;

} // end do_builtin function



void cleanup( command_t* p_cmd ) {
/* ------------------------------------------------------------------------------

This function is used to free memory that may be malloc'd for the name and argv 
fields in the command_t structure.  To be safe, you should also set the pointer 
values to NULL.
 
HINT(s): See man page for more information about free function
 
function:
	- parameter(s): pointer to a command_t structure
	- return: N/A

*/


	int i=0;
	
	while ( p_cmd->argv[i] != NULL ) {
		free( p_cmd->argv[i] );
		i++;
	}

	free( p_cmd->argv );
	free( p_cmd->path );	

} // end cleanup function


int equals( char* str1, const char* str2 ) {
/* ------------------------------------------------------------------------------

This function is used to compare to string values (not case sensitive)
 
function:
	- parameter(s): pointers to string 1 (str1) and string 2 (str2)
	- return: TRUE (1) or FALSE (0)

*/


	// First check length

	int len[] = {0,0};

	char* b_str1 = str1;
	const char* b_str2 = str2;

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
