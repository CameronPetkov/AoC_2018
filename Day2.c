// FILE: Day2.c
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 9/12/2018
// COMMENTS: 



#include "Day2.h"




void getDay2Ans()
{
    void (*calcType)( FILE *f, bool * ) = &getCheckSum;
    readFile( "input2.txt", calcType );
}




void getCheckSum( FILE *f, bool *success )
{
    char line[LINE_SIZE];
    int oneMatch = 0, twoMatch = 0;
    while ( fgets( line, LINE_SIZE, f ) != NULL )
    {
//        printf( "\n\n%s", line );
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

    int checkSum = oneMatch * twoMatch;
//    printf( "1 match: %d\n", oneMatch );
//    printf( "3 match: %d\n", twoMatch );
    printf( "Checksum found (Q2 Part 1): %d", checkSum );
}




int getNumOfRepeats( char line[LINE_SIZE], bool *success )
{
    int count = 0;
    bool twoFound = false, threeFound = false;

    do
    {
        int matches = compare( ( line + count ) );

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
    while ( ( !twoFound || !threeFound ) && ( line[count] != '\n' ) );

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




int compare( char *line )
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
        while ( line[ii] != '\n' );
    }

    return matches;
}