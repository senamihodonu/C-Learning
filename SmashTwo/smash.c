//Import definitions required to access functionality implemented elsewhere

#define _GNU_SOURCE
#include <stdio.h>     //Standard I/O functions and definitions
#include <stdlib.h>   //Standard library (includes exit function)
#include <string.h>  //String manipulation functions 
#include <unistd.h>
#include "smash.h"  //Bring in the definitions for our helper function
#include "history.h"

#define MAXLINE 4096
#define HISTORY_MAX 10

int main() {
    //setvbuf(stdout, NULL, _IOFBF, 0); //Disable buffering in the stdout stream
    char bfr[MAXLINE];
    // int i;
    fputs("$ ",stderr); //Output the first prompt
    //char* history;

    init_history();
      
    //Loop reading commands until EOF or error
    while (fgets(bfr, MAXLINE, stdin) != NULL) {
        bfr[strlen(bfr) - 1] = '\0'; //Replace newline with NULL
        executeCommand(bfr);
        fputs("$ ",stderr);
    }

    clear_history();
  
    return 0;
  
}
