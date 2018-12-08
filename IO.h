// FILE: IO.h
// AUTHOR: Cameron Petkov
// PURPOSE: N/A
// REFERENCE: N/A
// LAST MOD: 8/12/2018
// COMMENTS: 

#ifndef AOC_2018_IO_H
#define AOC_2018_IO_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "BinarySearchTree.h"




#define LINE_SIZE 30


int readFile( char fileName[] );
int sumFreq( FILE *f, bool *success );

#endif
