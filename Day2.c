// FILE: Day2.c
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 10/12/2018
// COMMENTS: 



#include "Day2.h"




void getDay2Ans()
{
    void (*calcType)( FILE *, bool * ) = &getCheckSum;
    readFile( "input2.txt", calcType );
    char *fileString = fileToString( "input2.txt" );
    getBoxIDs( fileString );
    free( fileString );
}




void getCheckSum( FILE *f, bool *success )
{
    char *line = ( char * ) malloc( LINE_SIZE * sizeof( char ) );
    int oneMatch = 0, twoMatch = 0;
    while ( fgets( line, LINE_SIZE, f ) != NULL )
    {
        int repeatCode = getNumOfRepeats( line, success );
        switch ( repeatCode )
        {
            case 1:
                oneMatch++;
//                printf("1 match!\n");
                break;
            case 2:
                twoMatch++;
//                printf("2 match!\n");
                break;
            case 3:
                oneMatch++;
                twoMatch++;
//                printf("1+2 match!\n");
                break;
        }
    }
    free( line );
    line = NULL;

    int checkSum = oneMatch * twoMatch;
//    printf( "1 match: %d\n", oneMatch );
//    printf( "3 match: %d\n", twoMatch );
    printf( "Checksum found (Q2 Part 1): %d\n", checkSum );
}




int getNumOfRepeats( char line[], bool *success )
{
    int count = 0;
    bool twoFound = false, threeFound = false;

    do
    {
        int matches = compareChar( line + count, count );

        if ( matches == 2 )
        {
            twoFound = true;
        }
        else if ( matches == 3 )
        {
            threeFound = true;
        }

        count++;
    }
    while ( ( !twoFound || !threeFound ) && ( count < LINE_SIZE ) );

    /* Code - 1: 2 repeats
     *        2: 3 repeats
     *        3: 2 & 3 repeats
     *        0: No OR 4+ repeats
     */
    short int repeatCode = 0;
    if ( twoFound )
    {
        repeatCode = 1;
    }
    if ( threeFound )
    {
        repeatCode += 2;
    }

    return repeatCode;
}




int compareChar( char *line, int offset )
{
    short int matches = 1;
    char ch = line[0];

    if ( ch != '\0' ) // i.e. Ignore all zero'd out chars (already considered)
    {
        int ii = 1;
        do
        {
            if ( ch == line[ii] )
            {
                // If there is a match, remove that from future comparisons by
                // zeroing it out, and then ignoring that character completely
                matches++;
                line[ii] = '\0';
            }
            ii++;
        }
        while ( ii < ( LINE_SIZE - offset ) );
    }

    return matches;
}




void getBoxIDs( char *line )
{
    bool match = false;

    int numLines = 1;
    int linesMax = getNumberOfLinesInString( line );
    int index = 0;
    do
    {
        index = compareLines( line, numLines, &match );
        if ( !match )
        {
            line += LINE_SIZE;
            numLines++;
        }
    }
    while ( !match && ( numLines <= linesMax ) );

    printf( "Common ID found (Q2 Part 2): " );
    int ii = 0;
    do
    {
        if ( line[ii] == line[LINE_SIZE * ( index - numLines ) + ii] )
        {
            printf( "%c", line[ii] );
        }
        ii++;
    }
    while ( line[numLines * LINE_SIZE + ii] != '\n' );
}




int compareLines( char *line, int offset, bool *match )
{
    int numLines = getNumberOfLinesInString( line );
    short int *nonMatches = ( short int * ) malloc( numLines * sizeof( short
    int ) );
    if ( nonMatches != NULL )
    {
        for ( int ii = 0; ii < numLines; ii++ )
        {
            nonMatches[ii] = 0;
        }
    }

    int ii = 0;
    while ( ii <= LINE_SIZE )
    {
        int wordNum = 1;
        while ( wordNum < numLines )
        {
            if ( nonMatches[wordNum] < 2 )
            {
                if ( line[ii] != line[ii + wordNum * LINE_SIZE] )
                {
                    nonMatches[wordNum] += 1;
                }
            }
            wordNum++;
        }
        ii++;
    }

    int matchIndex = 0;
    for ( int jj = 0; jj < numLines; jj++ )
    {
        if ( nonMatches[jj] == 1 )
        {
            matchIndex = jj + offset;
            *match = true;
        }
    }

    free( nonMatches );
    return matchIndex;
}




int getNumberOfLinesInString( char *string )
{
    int lines = 1;
    int ii = 0;
    while ( string[ii] != '\0' )
    {
        if ( string[ii] == '\n' )
        {
            lines++;
        }
        ii++;
    }

    return lines;
}