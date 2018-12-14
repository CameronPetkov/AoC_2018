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
    unsigned char *map = ( unsigned char * ) malloc(
            MAP_X_SIZE * MAP_Y_SIZE * sizeof( unsigned char ) );

    int numLines = getNumberOfLines( "input3.txt" );
    Rect *claims = ( Rect * ) malloc( numLines * sizeof( Rect ) );

//    claims[numLines] = '\0';

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

    for ( int ii = 0; ii < numLines; ii++ )
    {
        printf( "Coordinates are: (%d, %d) to (%d, %d). \n", claims[ii].p1.x,
                claims[ii].p1.y, claims[ii].p2.x, claims[ii].p2.y );
    }

    int overlapSize = getOverlap( map, claims );


    free( map );
    free( claims );
}




int getOverlap( unsigned char *map, Rect *claims )
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
                overlap++;
                printf( "%d\n", overlap );
            }
            jj--;
        }
        ii++;
    }
    return overlap;
}