//-----------------------------------------------------------------------------
//
// NAME
//  sed253 -- Simplified editor
//
// SYNOPSIS
//  sed253
//  sed253 -s pattern string
//  sed253 -d line1 line2
//
// DESCRIPTION
//  Simplified editor.  Copies lines read from stdin to stdout.  Options:
//
//  -s Substitute every occurrence of pattern with string
//  -d Delete line1 through line2 inclusive
//
// ERRORS
//  Prints usage message and exits abnormally for invalid commands.  Prints an
//  error message and exits abnormally for other issues.
//
// LIMITATIONS
//  Lines of text are limited to a maximum of 1023 chars.
//
// AUTHORS
//  Senami Hodonu...........................................................jrc
//
//-----------------------------------------------------------------------------

//Bring in the definitions for our helper functions
#include "copy.h"
#include "substitute.h"
#include "delete.h"

//Import definitions required to access functionality implemented elsewhere
#define _GNU_SOURCE
#include <stdio.h>    //Standard I/O functions and definitions
#include <stdlib.h>   //Standard library (includes exit function)
#include <string.h>  //String manipulation functions 

#define MAX 1023

//-----------------------------------------------------------------------------
//  usage -- Prints a usage message and exits with status=2
//-----------------------------------------------------------------------------
void usage(char * s) {
    
    //Print the usage message to stderr
    fprintf(stderr,"Usage:  sed253 [-s pattern string] [-d line1 line2]\n");
       
    //Force an exit.  This is equivalent to return 2 in main()
    exit(1);//Exit status is 1
    
}

//-----------------------------------------------------------------------------
// main -- the main function
//-----------------------------------------------------------------------------
int main(int argc, char **argv) {

    char * pattern; //Pointer to the given pattern
    char * string;  //Pointer to the user-supplied string
    char * line1;   //Pointer to the line 1
    char * line2;   //Pointer to the line 2
    
    
    //Check for -s or -d option and find the pattern in command-line args
    if (argc==4 && (strcmp(argv[1],"-s")==0)){ //Reference to pattern in args
        pattern = argv[2];
        string = argv[3];
        
        doSubstitute(pattern, string); //When executed with the -s option, sed253 replaces each 
                                       //occurrence of pattern in a line with string.
        
    } else if (argc==4 && (strcmp(argv[1],"-d")==0)) { 
        line1 = argv[2];
        line2 = argv[3];     
            
        doDelete(line1, line2); //When executed with the -d option, sed253 copies lines read from 
                                //stdin to stdout, omitting (deleting) lines numbered line1 through 
                                //line2 inclusive.
 
    } else if (argc==1) { 
        doCopy(); //When executed without a command-line argument, sed253 copies lines of text read 
                  //from stdin to stdout
                  
    } else {
        usage(argv[0]);//Publish usage message and error exit
    }

  return 0;
}

