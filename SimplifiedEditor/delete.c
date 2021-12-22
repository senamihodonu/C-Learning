//----------------------------------------------------------------------------
//
//  NAME Senami Hodonu
//  delete.c -- Implements the delete function
//
//----------------------------------------------------------------------------
#include <stdio.h>    //Standard I/O functions and definitions
#include <stdlib.h>   //Standard library (includes exit function)
#include <string.h>  //String manipulation functions 
#include "delete.h"

#define MAX 1023

int doDelete(char *line1, char *line2) {
  char inString[MAX+1];
  int count = 0;
  int startPoint;
  int endPoint;
  
  //Enter the lines to exclude
  sscanf(line1, "%d", &startPoint);
  sscanf(line2, "%d", &endPoint);
  
  printf("\n");
  //Checking for errors
  while(fgets(inString, sizeof(inString), stdin) != NULL) {
    if(strlen(inString) >= MAX){
      fprintf(stderr,"String exceeds the maximum allowable characters");
      exit(1);
    }
      
    count++;
    if((count<startPoint) || (count>endPoint)){
      printf("%s", inString);
    }
  }
  printf("\n");
  return 0;
}