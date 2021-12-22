//-----------------------------------------------------------------------------
//
//  NAME Senami Hodonu
//  copy.c -- Implements the copy function
//-----------------------------------------------------------------------------
#include <stdio.h>    //Standard I/O functions and definitions
#include <stdlib.h>   //Standard library (includes exit function)
#include <string.h>  //String manipulation functions 
#include "copy.h"
#define MAX 1023

int doCopy(void) {

  int ch;
    //Loop copying each byte from stdin to stout
    printf("\n");
    while((ch = getchar())  != EOF) {
    putchar(ch);
  }
  return 0;
}
