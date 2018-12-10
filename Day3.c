// FILE: Day3.c
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 10/12/2018
// COMMENTS: 

#include "Day3.h"




int getOverlap();




void getDay3Ans()
{
    void (*calcType)( FILE *, bool * ) = &storeCoordinates;
    readFile( "input3.txt", calcType );

}




void storeCoordinates( FILE *f, bool *success )
{
    unsigned char *map = ( unsigned char * ) malloc( 1000 * 1000 * sizeof(
            unsigned char ) );

    short int *coordinates = ( short int * ) malloc( 4 * getNumberOfLines
            ( "input3.txt" ) * sizeof( short int ) + 1 );

    coordinates[4 * getNumberOfLines( "input3.txt" ) * sizeof( short int )] =
            '\0';

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

        printf( "Coordinates are: (%d, %d) to (%d, %d). \n", x1, y1, x2, y2 );
        coordinates[ii] = x1;
        coordinates[ii + 1] = y1;
        coordinates[ii + 2] = x2;
        coordinates[ii + 3] = y2;
        ii++;
    }

    int overlapSize = getOverlap( map, coordinates );


    free( map );
    free( coordinates );
}




int getOverlap( unsigned char *map, short int *coordinates )
{
    int overlap = 0;
    int ii = 0;
    while ( coordinates[ii] != '\0' )
    {
        int jj = ii;
        while ( coordinates[jj] != '\0' )
        {
            if ( ( coordinates[ii] > coordinates[jj] ) &&
                 ( coordinates[ii + 2] < coordinates[jj + 2] ) &&
                 ( coordinates[ii + 1] < coordinates[jj + 1] ) &&
                 ( coordinates[ii + 3] > coordinates[jj + 3] ) )
            {
                //overlap += getIntersection();
            }
            jj += 4;
        }
        ii += 4;
    }
    return overlap;
}