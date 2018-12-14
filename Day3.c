// FILE: Day3.c
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 10/12/2018
// COMMENTS: 

#include "Day3.h"




void getDay3Ans()
{
    void (*calcType)( FILE *, bool * ) = &storeCoordinates;
    readFile( "input3.txt", calcType );
}




void storeCoordinates( FILE *f, bool *success )
{
    //Space for 1000 * 1000 min grid size
    unsigned char **map = ( unsigned char ** ) malloc( MAP_Y_SIZE * sizeof(
            unsigned char * ) );
    if ( map != NULL )
    {
        for ( int ii = 0; ii < MAP_Y_SIZE; ii++ )
        {
            map[ii] = ( unsigned char * ) malloc( MAP_X_SIZE * sizeof( unsigned
            char ) );
            for ( int jj = 0; jj < MAP_X_SIZE; jj++ )
            {
                map[ii][jj] = 0;
            }
        }
    }

    int numLines = getNumberOfLines( "input3.txt" );
    Rect *claims = ( Rect * ) malloc( numLines * sizeof( Rect ) );

    char line[LINE_SIZE];
    for ( int ii = 0; ii < numLines; ii++ )
    {
        fgets( line, LINE_SIZE, f );
        short int id = 0, x1 = 0, y1 = 0, xOffset = 0, yOffset = 0;
        sscanf( line, "#%hu @ %hu,%hu: %hux%hu", &id, &x1, &y1, &xOffset,
                &yOffset );

        short int x3 = x1 + xOffset - 1;
        short int y3 = y1 + yOffset - 1;

        claims[ii].p1.x = x1;
        claims[ii].p1.y = y1;
        claims[ii].p2.x = x3;
        claims[ii].p2.y = y1;
        claims[ii].p3.x = x3;
        claims[ii].p3.y = y3;
        claims[ii].p4.x = x1;
        claims[ii].p4.y = y3;

        printf( "Coordinates are: (%d, %d) to (%d, %d) to (%d, %d) to (%d, %d)."
                "\n", x1, y1, x3, y1, x3, y3, x1, y3 );
    }

    int overlapSize = getOverlap( map, claims );
    printf( "Overlap size: %d\n", overlapSize );

    for ( int jj = 0; jj < MAP_Y_SIZE; jj++ )
    {
        free( map[jj] );
    }
    free( map );
    free( claims );
}




int getOverlap( unsigned char **map, Rect *claims )
{
    int overlap = 0;
    int ii = 0;
    int numLines = getNumberOfLines( "input3.txt" );
    while ( ii < numLines - 1 )
    {
        int jj = numLines - 1;
//        printf( "\n(%d, %d) and (%d, %d)\n", claims[ii].p1.x, claims[ii].p1
//                .y, claims[ii].p2.x, claims[ii].p2.y );
        while ( jj > ii )
        {
//            printf( "(%d, %d) and (%d, %d)\n", claims[jj].p1.x, claims[jj].p1
//                    .y, claims[jj].p2.x, claims[jj].p2.y );
            Point *p;
            if ( anyPointIntersects( claims, ii, jj, p ) )
            {

                overlap += getPointIntersect( claims, map, ii, jj, &p );
            }
           /* if ( point1Intersects( claims, ii, jj ) )
            {
                overlap += getPoint1Intersect( claims, map, ii, jj );
            }
            else if ( point2Intersects( claims, ii, jj ) )
            {
                overlap += getPoint2Intersect( claims, map, ii, jj );
            }*/
            jj--;
        }
        ii++;
        printf( "%d\n", overlap );
    }
    return overlap;
}




bool anyPointIntersects( Rect *claims, int ii, int jj, Point *p )
{
    bool pointPresent = false;

    Point *ptr = &claims[ii].p1;
    for( int kk = 0; kk < 4; kk++ )
    {
        if ( ( ptr->x >= claims[jj].p1.x ) &&
             ( ptr->x <= claims[jj].p2.x ) &&
             ( ptr->y >= claims[jj].p1.y ) &&
             ( ptr->y <= claims[jj].p3.y ) )
        {
            pointPresent = true;
            p = ptr;
        }
        ptr = ptr + 1;
    }
    return pointPresent;
}




int getPointIntersect( Rect *claims, unsigned char **map, int ii, int jj,
        Point *p )
{
    int area = 0;

    return area;
}




bool point1Intersects( Rect *claims, int ii, int jj )
{
    return ( ( claims[ii].p1.x >= claims[jj].p1.x ) &&
             ( claims[ii].p1.x <= claims[jj].p2.x ) &&
             ( claims[ii].p1.y >= claims[jj].p1.y ) &&
             ( claims[ii].p1.y <= claims[jj].p2.y ) );
}




bool point2Intersects( Rect *claims, int ii, int jj )
{
    return ( ( claims[ii].p2.x >= claims[jj].p1.x ) &&
             ( claims[ii].p2.x <= claims[jj].p2.x ) &&
             ( claims[ii].p2.y >= claims[jj].p1.y ) &&
             ( claims[ii].p2.y <= claims[jj].p2.y ) );
}




//down-right
int getPoint1Intersect( Rect *claims, unsigned char **map, int ii, int jj )
{
    int area = 0, width = 0, height = 0, startX = 0, startY = 0;

    printf( "(%d, %d) intersects (%d, %d)\n", claims[ii].p1.x, claims[ii].p1
            .y, claims[jj].p2.x, claims[jj].p2.y );

    if ( claims[ii].p2.y > claims[jj].p1.y )
    {
        height = claims[jj].p2.y - claims[ii].p1.y;
    }
    else
    {
        height = claims[ii].p2.y - claims[ii].p1.y;
    }
    if ( claims[ii].p2.x > claims[jj].p1.x )
    {
        width = claims[jj].p2.x - claims[ii].p1.x;
    }
    else
    {
        width = claims[ii].p2.x - claims[ii].p1.x;
    }

    startX = claims[ii].p1.x;
    startY = claims[ii].p1.y;
    area = updateMap( map, startX, startY, height, width );

    return area;
}




//up-left
int getPoint2Intersect( Rect *claims, unsigned char **map, int ii, int jj )
{
    int area = 0, width = 0, height = 0, startX = 0, startY = 0;


    printf( "(%d, %d) intersects (%d, %d)\n", claims[ii].p2.x, claims[ii].p2
            .y, claims[jj].p1.x, claims[jj].p1.y );

    if ( claims[ii].p2.y < claims[jj].p1.y )
    {
        height = claims[jj].p1.y - claims[ii].p2.y;
        startY = claims[jj].p1.y;
    }
    else
    {
        height = claims[ii].p2.y - claims[ii].p1.y;
        startY = claims[ii].p1.y;
    }
    if ( claims[ii].p2.x < claims[jj].p1.x )
    {
        width = claims[jj].p1.x - claims[ii].p2.x;
        startX = claims[jj].p1.x;
    }
    else
    {
        width = claims[ii].p2.x - claims[ii].p1.x;
        startX = claims[ii].p1.x;
    }

    area = updateMap( map, startX, startY, height, width );

    return area;
}




int updateMap( unsigned char **map, int ii, int jj, int height, int width )
{
    int area = 0;
    for ( int xx = ii; xx < ii + width; xx++ )
    {
        for ( int yy = jj; yy < jj + height; yy++ )
        {
            if ( map[xx][yy] == 0 )
            {
                area++;
                map[xx][yy] = 1;
            }
        }
    }

    return area;
}