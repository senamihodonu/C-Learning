//-----------------------------------------------------------------------------
//
//  NAME Senami Hodonu
//  substitute.h -- Define prototypes and symbols for using substitute.c
//
//  Reads lines from stdin, performs the requested substition of pattern
//  with string (or leaves the text unchanged if pattern is not found),
//  and writes the possibly updated line to stdout.
//
//  All pattern matching is case sensitive.
//
//-----------------------------------------------------------------------------

#ifndef SUBSTITUTE_H
#define SUBSTITUTE_H
// Define function prototypes
int doSubstitute(char *pattern, char *givenString);  //Returns exit status
#endif /*SUBSTITUTE_H*/