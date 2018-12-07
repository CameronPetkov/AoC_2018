// FILE: IO.h
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 
// COMMENTS: 

#ifndef AOC_2018_IO_H
#define AOC_2018_IO_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE 30


int readFile( char fileName[] );
int sumFreq( FILE *f, bool *success );

#endif
