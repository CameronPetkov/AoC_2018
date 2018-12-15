// FILE: Day3.c
// AUTHOR: Cameron Petkov
// PURPOSE: Solve day 3 challenges
// REFERENCE:
// LAST MOD: 15/12/2018
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
        short int id = 0, x1 = 0, y1 = 0, width = 0, height = 0;
        sscanf( line, "#%hu @ %hu,%hu: %hux%hu", &id, &x1, &y1, &width,
                &height );

        claims[ii].p1.x = x1;
        claims[ii].p1.y = y1;
        claims[ii].width = width;
        claims[ii].height = height;

//        printf( "Coordinates are: (%d, %d).\n", x1, y1 );
    }

    int overlapSize = makeMap( map, claims, numLines );
    printf( "Overlap size (Q3 Part 1): %d\n", overlapSize );

    for ( int jj = 0; jj < MAP_Y_SIZE; jj++ )
    {
        free( map[jj] );
    }
    free( map );
    free( claims );
}




int makeMap( unsigned char **map, Rect *claims, int claimsSize )
{
    int area = 0;

    for ( int ii = 0; ii < claimsSize; ii++ )
    {
        int jjLimit = claims[ii].p1.y + claims[ii].height;
        for ( int jj = claims[ii].p1.y; jj < jjLimit; jj++ )
        {
            int kkLimit = claims[ii].p1.x + claims[ii].width;
            for ( int kk = claims[ii].p1.x; kk < kkLimit; kk++ )
            {
//                printf("(%d, %d)\n", kk, jj);
                if ( map[jj][kk] == 0 )
                {
                    map[jj][kk] = 1;
                }
                else if ( map[jj][kk] == 1 )
                {
                    area++;
                    map[jj][kk] += 1;
                }
                else
                {
                    map[jj][kk] += 1;
                }
            }
        }
    }

    return area;
}