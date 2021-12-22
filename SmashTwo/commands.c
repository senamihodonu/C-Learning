#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>   //Standard library (includes exit function)
#include <sys/wait.h>

#include "smash.h"
#include "history.h"

char* args[120]; //user command
int exitStatus = 0;

/*Implement function executeCommand in commands.c
to parse its single parameter into space-separated 
tokens using the strtok.*/
void executeCommand(char* str){

/********** declaring variables **********/
    const char DELIM[2] = " ";
    char* token;
    char argc[120];
    strncpy(argc, str, 120); 
    int i = 0; //argument count
    int seq = 0;
    char *dirname;
    

  
    /*to get the first token*/
    token = strtok(str, DELIM);
    /*walk through other token*/
    while(token != NULL) { 
        args[i] = token;
        
        token = strtok(NULL, DELIM);
        i++;        
    }
    args[i] = NULL; 
    
    //If there are no inputs
    if(i == 0){
      //exitStatus = 0;
    return;
    } 
    
    //Implementing smash exit's command
    if(strcmp(args[0], "exit") == 0) {
        printf("\nExiting Shell... Goodbye!\n");
        exit(exitStatus);
    } //Implementing smash cd command
    else if ((strcmp(args[0], "cd") == 0) && (chdir(args[1]) == 0) && (args[1] != NULL)) { 
          dirname = args[1];
          printf("changing directory ... \n");
          //chdir(dirname);
          getcwd(dirname, sizeof(dirname));
          puts(dirname);
          //exit(0);
          seq++;     
    } 
    else if ((strcmp(args[0], "cd") == 0) && chdir(args[0]) == -1) {
           exitStatus = 1;
           perror(args[1]);
           seq++;
    } 
    //Implementing smash history
 		else if(strcmp(args[0], "history") == 0) {
        seq++;
        print_history(seq);
		} else {
         exitStatus = 127; 
//         for (int x = 0; x < i; x++){
//         //printf("[%d] %s\n", x, args[x]);
//         
//         executeExternalCommand();
//         
//         }
         executeExternalCommand();
         seq++;
         
    }  
    add_history(argc, exitStatus);

}

//Executes an external command based on argv
//Prints error message if command does not exist
void executeExternalCommand() {

    int pid = fork();
    
    //child process
    if (pid == 0) {
        execvp(args[0], args);
        exitStatus = 0;
      if (execvp(args[0], args) < 0) {
        fprintf(stderr, "%s: Command not found\n",args[0]);
        exitStatus = 127;
      } else {
        fprintf(stderr, "Process complete\n");
        exit(0);
        }
    } else {
      wait(NULL);
      printf("\n...\n");
    }

}
