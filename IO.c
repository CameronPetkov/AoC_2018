// FILE: IO.c
// AUTHOR: Cameron Petkov
// PURPOSE: Read in file and sum frequency/detect duplicate frequency
// REFERENCE: N/A
// LAST MOD: 9/12/2018
// COMMENTS:

#include "IO.h"




void readFile( char fileName[], void (*processType)( FILE *, bool * ) )
{
    bool success = true;

    FILE *f = fopen( fileName, "r" );
    if ( f == NULL )
    {
        perror( "Error reading file" );
        success = false;
    }
    else
    {
        processType( f, &success );

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