// FILE: IO.c
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 
// COMMENTS:

#include "IO.h"




int readFile( char fileName[] )
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
        sum = sumFreq( f, &success );

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

    return sum;
}




int sumFreq( FILE *f, bool *success )
{
    static int sum = 0;

    char line[LINE_SIZE];
    while ( ( fgets( line, LINE_SIZE, f ) != NULL ) && success )
    {
        printf( "%s", line );
        char operation = line[0];
        //printf( "%c\n", operation );

        char *freqString = line + 1;
        printf( "%s", freqString );

        char *ptr;
        int freqShift = strtol( freqString, &ptr, 10 );
        printf( "%d\n\n", freqShift );
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
    }
    return sum;
}