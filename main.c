// FILE: main.c
// AUTHOR: Cameron Petkov
// PURPOSE: MAIN
// REFERENCE:
// LAST MOD: 8/12/2018
// COMMENTS:


#include <stdio.h>
#include "Day1.h"
#include "Day2.h"
#include "IO.h"




int main()
{
    void (*calcType)( FILE *f, bool * ) = &calcFreq;
    getDay1Ans( calcType );
    calcType = &calcCheckSum;
    getDay2Ans( calcType );
    return 0;
}