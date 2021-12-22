#define _GNU_SOURCE
#include <stdio.h>     //Standard I/O functions and definitions
#include <stdlib.h>   //Standard library (includes exit function)
#include <string.h>  //String manipulation functions 
#include <unistd.h>
#include "history.h"

/**
* Builds data structures for recording cmd history
*/
static Cmd **history;
static int i = 0;
int currIndex;
int curr;
int past;

void init_history(void) {
  curr = 0;
	past = 0;
 currIndex = 0;
  history = (Cmd **) malloc(HISTORY_MAX * sizeof(Cmd *));
 for(i = 0; i < HISTORY_MAX; i++) {
   history[i] = (Cmd *) malloc(sizeof(Cmd));
   history[i]->cmd = (char *) malloc(MAXLINE * sizeof(char));
   history[i]->exitStatus = 0;
  }
}

//Adds an entry to the history
void add_history(char *cmd, int exitStatus) { 
  if (curr > HISTORY_MAX){
    past = (curr % HISTORY_MAX) + 1;
  }
  if (curr < HISTORY_MAX){
      currIndex++;
  }
  history[curr % HISTORY_MAX]->cmd = strdup(cmd);
  history[curr % HISTORY_MAX]->exitStatus = exitStatus;
  //puts(history[i] ->cmd);
  curr++;
}

//Frees all malloc'd memory in the history
void clear_history(void) {
  for(i = 0; i < HISTORY_MAX; i++) {
   free(history[i] ->cmd);
   free(history[i]);
   }
   free(history);
} 

//Prints the history to stdout
void print_history(int firstSequenceNumber){
  for(i = 0; i < currIndex; i++) {
    if (curr < HISTORY_MAX) {
        printf("%d [%d] %s\n", i + 1, history[i]->exitStatus, history[i]->cmd);
    } else {
        printf("%d [%d] %s\n", i + (curr - 9), history[(i + past) % HISTORY_MAX]->exitStatus, history[(i + past) % HISTORY_MAX]->cmd);
    }
  }
}

