// FILE: IO.c
// AUTHOR: Cameron Petkov
// PURPOSE: Allow easy file operations
// REFERENCE: N/A
// LAST MOD: 15/12/2018
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




char *fileToString( char fileName[] )
{
    bool success = true;
    char *fileString;
    FILE *f = fopen( fileName, "r" );
    if ( f == NULL )
    {
        perror( "Error reading file" );
        success = false;
    }
    else
    {
        // Code adapted from: StackOverflow user Enkelli,
        // https://stackoverflow.com/a/14002993
        fseek( f, 0, SEEK_END );
        long fileSize = ftell( f );
        rewind( f );

        fileString = ( char * ) malloc( fileSize + 1 );
        fread( fileString, fileSize, 1, f );
        fclose( f );

        fileString[fileSize] = '\0';
    }
    return fileString;
}




int getNumberOfLines( char fileName[] )
{
    int lines = 0;
    bool success;
    FILE *f = fopen( fileName, "r" );
    if ( f == NULL )
    {
        perror( "Error reading file" );
        success = false;
    }
    else
    {
        while ( !feof( f ) )
        {
            if ( fgetc( f ) == '\n' )
            {
                lines++;
            }
        }
        fclose( f );
    }
    lines++;
    return lines;
}