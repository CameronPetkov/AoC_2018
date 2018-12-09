// FILE: Day2.h
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 8/12/2018
// COMMENTS: 

#ifndef AOC_2018_DAY2_H
#define AOC_2018_DAY2_H

#include <stdbool.h>

#include "IO.h"




#define LINE_SIZE 27

void getDay2Ans();
void getCheckSum( FILE *f, bool *success );
int getNumOfRepeats( char line[], bool *success );
int compare( char *line, int offset );

#endif //AOC_2018_DAY2_H