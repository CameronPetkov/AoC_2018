// FILE: IO.h
// AUTHOR: Cameron Petkov
// PURPOSE: N/A
// REFERENCE: N/A
// LAST MOD: 9/12/2018
// COMMENTS: 

#ifndef AOC_2018_IO_H
#define AOC_2018_IO_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "BinarySearchTree.h"




#define LINE_SIZE 30


void readFile( char fileName[], void (*processType)( FILE *, bool * ) );
void calcFreq( FILE *f, bool *success );
void getCheckSum( FILE *f, bool *success );
int getNumOfRepeats( char line[LINE_SIZE], bool *success );
int compare( char *line );

#endif
