#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"

int main( int argc, char** argv ) {

	int done = FALSE;
	int i = 0;

	char shell_cmd[100];

	command_t command;

	command.path = malloc(sizeof(char)*100);
	command.argv = malloc(sizeof(char*)*50);
	
	for ( i=0; i<50; i++ ) command.argv[i] = malloc(sizeof(char)*100);

    printf("\nHW2 Shell: Type 'exit' to exit this shell.\n\n");

	while ( !done ) {

		printf("[%s]~/[%s]$> ", getenv("USER"), getenv("HOME"));
		gets( shell_cmd );

		parse( shell_cmd, &command );

		if ( ( command.argc > 0 ) && equals( command.path, "exit" )  ) {

			done = TRUE;
        }else if( ( command.argc > 0 ) && equals( command.path, "helper" )  ){

            printf("\nRUN HELPER\n");
		} else if ( command.argc == ERROR ) { 

			fprintf( stderr, "%s: command not found!\n", command.path );

		} else if ( command.argc > 0 ) {

			if ( is_builtin( &command ) ) {

				if ( do_builtin( &command ) != SUCCESSFUL ) {

					fprintf( stderr, "%s command failed: requested folder [%s] does not exist!\n", 
					command.path, command.argv[0] );

				}

			} else if ( execute( &command ) != SUCCESSFUL ) {

				fprintf( stderr, "%s command failed!\n", command.path );

			} 

		}

	}

	cleanup( &command );

	return 0;

} // end main function
