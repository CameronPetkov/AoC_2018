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
            for( int jj = 0; jj < MAP_X_SIZE; jj++)
            {
                map[ii][jj] = 0;
            }
        }
    }

    int numLines = getNumberOfLines( "input3.txt" );
    Rect *claims = ( Rect * ) malloc( numLines * sizeof( Rect ) );

    char line[LINE_SIZE];
    int ii = 0;
    while ( fgets( line, LINE_SIZE, f ) != NULL )
    {
        short int id = 0, x1 = 0, y1 = 0, xOffset = 0, yOffset = 0;
        sscanf( line, "#%d @ %d,%d: %dx%d", &id, &x1, &y1, &xOffset, &yOffset );

        short int x2 = x1 + xOffset;
        short int y2 = y1 + yOffset;
        x1++;
        y1++;

//        printf( "Coordinates are: (%d, %d) to (%d, %d). \n", x1, y1, x2, y2 );

        claims[ii].p1.x = x1;
        claims[ii].p1.y = y1;
        claims[ii].p2.x = x2;
        claims[ii].p2.y = y2;

        ii++;
    }

    /*for ( int jj = 0; jj < numLines; jj++ )
    {
        printf( "Coordinates are: (%d, %d) to (%d, %d). \n", claims[jj].p1.x,
                claims[jj].p1.y, claims[jj].p2.x, claims[jj].p2.y );
    }*/

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
    while ( ii < numLines )
    {
        int jj = ii;
        while ( jj >= 0 )
        {

            if ( ( claims[ii].p1.x > claims[jj].p1.x ) &&
                 ( claims[ii].p1.x < claims[jj].p2.x ) &&
                 ( claims[ii].p1.y > claims[jj].p1.y ) &&
                 ( claims[ii].p1.y < claims[jj].p2.y ) )
            {
                overlap += getPoint1Intersect( claims, map, ii, jj );
            }
            else if ( ( claims[ii].p2.x > claims[jj].p1.x ) &&
                      ( claims[ii].p2.x < claims[jj].p2.x ) &&
                      ( claims[ii].p2.y > claims[jj].p1.y ) &&
                      ( claims[ii].p2.y < claims[jj].p2.y ) )
            {
                overlap += getPoint2Intersect( claims, map, ii, jj );
            }
            jj--;
        }
        ii++;
        printf( "%d\n", overlap );
    }
    return overlap;
}




//down-right
int getPoint1Intersect( Rect *claims, unsigned char **map, int ii, int jj )
{
    int area = 0, width = 0, height = 0, startX = 0, startY = 0;

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

    if ( claims[ii].p2.y < claims[jj].p1.y )
    {
        height = claims[ii].p2.y - claims[jj].p1.y;
        startY = claims[jj].p1.y;
    }
    else
    {
        height = claims[ii].p2.y - claims[ii].p1.y;
        startY = claims[ii].p1.y;
    }
    if ( claims[ii].p2.x < claims[jj].p1.x )
    {
        width = claims[ii].p2.x - claims[jj].p1.x;
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