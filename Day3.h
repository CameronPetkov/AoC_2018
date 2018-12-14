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
    Point p3;
    Point p4;
} Rect;

void getDay3Ans();
void storeCoordinates( FILE *f, bool *success );
int getOverlap( unsigned char **map, Rect *claims );
bool anyPointIntersects( Rect *claims, int ii, int jj, Point *p );
bool point1Intersects( Rect *claims, int ii, int jj );
bool point2Intersects( Rect *claims, int ii, int jj );
int getPointIntersect( Rect *claims, unsigned char **map, int ii, int jj,
                       Point *p );
int getPoint1Intersect( Rect *claims, unsigned char **map, int ii, int jj );
int getPoint2Intersect( Rect *claims, unsigned char **map, int ii, int jj );
int updateMap( unsigned char **map, int ii, int jj, int height, int width );

#endif //AOC_2018_DAY3_H
