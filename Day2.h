// FILE: Day2.h
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 10/12/2018
// COMMENTS: 

#ifndef AOC_2018_DAY2_H
#define AOC_2018_DAY2_H

#include <stdbool.h>

#include "IO.h"





void getDay2Ans();
void getCheckSum( FILE *f, bool *success );
int getNumOfRepeats( char line[], bool *success );
int compareChar( char *line, int offset );
void getBoxIDs( char *line );
int compareLines( char *line, int offset, bool *match );
int getNumberOfLinesInString( char* string );

#endif //AOC_2018_DAY2_H