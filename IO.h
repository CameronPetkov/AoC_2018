// FILE: IO.h
// AUTHOR: Cameron Petkov
// PURPOSE: N/A
// REFERENCE: N/A
// LAST MOD: 10/12/2018
// COMMENTS: 

#ifndef AOC_2018_IO_H
#define AOC_2018_IO_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "BinarySearchTree.h"




#define LINE_SIZE 27


void readFile( char fileName[], void (*processType)( FILE *, bool * ) );
char *fileToString( char fileName[] );
int getNumberOfLines( char fileName[] );

#endif