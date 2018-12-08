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

    if ( !success )
    {
        fprintf( stderr, "Errors present while reading file. \n" );
    }

    return sum;
}




int sumFreq( FILE *f, bool *success )
{
    int sum = 0;

    char line[LINE_SIZE];
    while ( ( fgets( line, LINE_SIZE, f ) != NULL ) && success )
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
    }
    return sum;
}