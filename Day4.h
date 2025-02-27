// FILE: Day4.h
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 02/01/2019
// COMMENTS: 

#ifndef AOC_2018_DAY4_H
#define AOC_2018_DAY4_H

#include <string.h>

#include "IO.h"
#include "Comparison.h"
#include "HashTable.h"




#define TABLE_SIZE 100


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
int getMostSleepyGuard( Log *logs, int numLines );
int getMostSleptMinute( int id, Log *logs, int numLines );
int getMaxValue( const int *mostCommonMinute );
int populateGuardHT( struct HashTable *ht, int size, Log *logs, int numLines );
int getMostSleepyMethod2( Log *logs, int numLines );

#endif //AOC_2018_DAY4_H
