// FILE: Day4.h
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 15/12/2018
// COMMENTS: 

#ifndef AOC_2018_DAY4_H
#define AOC_2018_DAY4_H

#include "IO.h"
#include "Comparison.h"
#include "string.h"



typedef struct
{
    int year;
    int month;
    int day;
} Date;

typedef struct
{
    int hour;
    int minute;
} Time;

typedef struct
{
    Date date;
    Time time;
    char info[50];
} Log;


void getDay4Ans();
void sortDates( FILE *f, bool *success );

#endif //AOC_2018_DAY4_H
