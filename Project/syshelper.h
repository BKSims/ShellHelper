
#define SUCCESSFUL 0
#define ERROR -1

#define TRUE 1
#define FALSE 0

#define DEBUG 1

/**
-----------------------------------------------------------------------
*/
int equal_to( char* str1, char* str2 );

/** 
-----------------------------------------------------------------------
	This function is used to compare non case-sensitive string
	values
-----------------------------------------------------------------------
*/

void reformat_string(char *src, char *dst);
/** 
-----------------------------------------------------------------------
	This function is used to convert a string into a lower-case,
	non-punctuated version
-----------------------------------------------------------------------
*/

int parsing(char* line, int exit);

/** 
-----------------------------------------------------------------------
	This function is used to parse the commands entered into the
	terminal
-----------------------------------------------------------------------
*/

int shellHelper( int argc, char** argv );

/** 
-----------------------------------------------------------------------
	This function is used to run syshelper.c
-----------------------------------------------------------------------
*/
