// FILE: Day3.h
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 10/12/2018
// COMMENTS: 

#ifndef AOC_2018_DAY3_H
#define AOC_2018_DAY3_H

#include "IO.h"

void getDay3Ans();
void storeCoordinates( FILE *f, bool *success );
int getOverlap( unsigned char *map, short int *coordinates );

#endif //AOC_2018_DAY3_H
