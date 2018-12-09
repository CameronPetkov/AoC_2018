// FILE: Day1.c
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD:
// COMMENTS:


#include "Day1.h"

#include <stdio.h>




void getDay1Ans()
{
    void (*calcType)( FILE *, bool * ) = &calcFreq;
    readFile( "input.txt", calcType );
}




void calcFreq( FILE *f, bool *success )
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

        if ( q1print )
        {
            printf( "Series sum found (Q1 Part 1): %d\n", sum );
            q1print = false;
        }
        rewind( f );
    }

    clearTree( &root );
}
