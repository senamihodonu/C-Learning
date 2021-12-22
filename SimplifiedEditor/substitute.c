//-----------------------------------------------------------------------------
//
//  NAME Senami Hodonu
//  substitute.c -- Implementing the substitute function
//-----------------------------------------------------------------------------  

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "substitute.h"

#define MAX 1023

int doSubstitute(char *pattern, char *givenString) {
  char string[MAX+1];
  int patternLength = strlen(pattern);
  
  printf("\n");
  //Handling errors
  while(fgets(string, sizeof(string), stdin) != NULL){
    if (strlen(string) > MAX){
      fprintf(stderr, "Exceeded the MAX characters \n");
      exit(1);
    }
    //Substitute implementation
    while(strstr(string, pattern)){
      char first[MAX] = "";
      strncpy(first, string, (strlen(string) - strlen((strstr(string, pattern)))));
      char *secondPattern = strstr(string, pattern);
      char *second = secondPattern + patternLength;
      strncat(first, givenString, MAX);
      strncat(first, second, MAX);
      strncpy(string, first, MAX);
    }
  printf("%s", string);
  }
return 0;  //Returns exit status
}