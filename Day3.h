// FILE: Day3.h
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 10/12/2018
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
    Point p2;
} Rect;

void getDay3Ans();
void storeCoordinates( FILE *f, bool *success );
int getOverlap( unsigned char **map, Rect *claims );
int getPoint1Intersect( Rect *claims, unsigned char **map, int ii, int jj );
int getPoint2Intersect( Rect *claims, unsigned char **map, int ii, int jj );
int updateMap( unsigned char **map, int ii, int jj, int height, int width );

#endif //AOC_2018_DAY3_H
