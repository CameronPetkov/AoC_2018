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




void getDay2Ans();
void getCheckSum( FILE *f, bool *success );
int getNumOfRepeats( char line[LINE_SIZE], bool *success );
int compare( char *line );

#endif //AOC_2018_DAY2_H