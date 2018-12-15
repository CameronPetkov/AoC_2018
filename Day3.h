// FILE: Day3.h
// AUTHOR: Cameron Petkov
// PURPOSE: N/A
// REFERENCE:
// LAST MOD: 15/12/2018
// COMMENTS: 

#ifndef AOC_2018_DAY3_H
#define AOC_2018_DAY3_H

#include "IO.h"




#define MAP_X_SIZE 1000
#define MAP_Y_SIZE MAP_X_SIZE


typedef struct
{
    short int x;
    short int y;
} Point;


typedef struct
{
    Point p1;
    int width;
    int height;
} Rect;

void getDay3Ans();
void storeCoordinates( FILE *f, bool *success );
int findOverlapArea( unsigned char **map, Rect *claims, int claimsSize );
int findUniqueClaims( unsigned char **map, Rect *claims, int claimsSize );

#endif //AOC_2018_DAY3_H
