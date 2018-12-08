// FILE: Day1.c
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD:
// COMMENTS:


#include "Day1.h"

#include <stdio.h>




void getDay1Ans( void (*calcType)( FILE *, bool * ) )
{
    readFile( "input.txt", calcType );
}