// FILE: IO.c
// AUTHOR: Cameron Petkov
// PURPOSE: Read in file and sum frequency/detect duplicate frequency
// REFERENCE: N/A
// LAST MOD: 8/12/2018
// COMMENTS:

#include "IO.h"




void readFile( char fileName[] )
{
    bool success = true;
    int sum;

    FILE *f = fopen( fileName, "r" );
    if ( f == NULL )
    {
        perror( "Error reading file" );
        success = false;
    }
    else
    {
        sumFreq( f, &success );

        if ( ferror( f ) )
        {
            perror( "Error while reading from file" );
            success = false;
        }
        else if ( !success )
        {
            fprintf( stderr, "Error with file format \n" );
        }

        fclose( f );

    }

    if ( !success )
    {
        fprintf( stderr, "Errors present while reading file. \n" );
    }
}




void sumFreq( FILE *f, bool *success )
{
    int sum = 0;
    bool q1print = true;

    char line[LINE_SIZE];
    TreeNode *root = ( TreeNode * ) malloc( sizeof( TreeNode ) );
    createNode( &root, 0 );
    bool found = false;
    while ( !found )
    {
        while ( ( fgets( line, LINE_SIZE, f ) != NULL ) && success && !found )
        {
            char operation = line[0];

            char *freqString = line + 1;
            char *ptr;
            int freqShift = strtol( freqString, &ptr, 10 );

            if ( operation == '-' )
            {
                sum -= freqShift;
            }
            else if ( operation == '+' )
            {
                sum += freqShift;
            }
            else
            {
                *success = false;
            }
            found = insert( &root, sum );
        }

        if(q1print)
        {
            printf( "Series sum found (Q1 Part 1): %d\n", sum );
            q1print = false;
        }
        rewind( f );
    }
}