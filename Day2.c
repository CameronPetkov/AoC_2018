// FILE: Day2.c
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 9/12/2018
// COMMENTS: 



#include "Day2.h"




void getDay2Ans( void (*calcType)( FILE *, bool* ) )
{
    readFile( "input2.txt", calcType );
}