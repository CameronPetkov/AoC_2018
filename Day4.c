// FILE: Day4.c
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 02/01/2019
// COMMENTS: 

#include "Day4.h"




void getDay4Ans()
{
    void (*calcType)( FILE *, bool * ) = &sortDates;
    readFile( "input4.txt", calcType );
}




void sortDates( FILE *f, bool *success )
{
    int numLines = getNumberOfLines( "input4.txt" );
    Log *logs = ( Log * ) malloc( numLines * sizeof( Log ) );

    char line[LINE_SIZE + 30];
    for ( int ii = 0; ii < numLines; ii++ )
    {
        fgets( line, LINE_SIZE + 30, f );
        int year = 0, month = 0, day = 0, hour = 0, minute = 0;
        char info[50];
        sscanf( line, "[%d-%d-%d %d:%d] %50[^\n]", &year, &month, &day,
                &hour, &minute, info );

        logs[ii] = ( Log ) {.date.year = year, .date.month = month, .date.day =
        day, .time.hour = hour, .time.minute = minute};
        strcpy( logs[ii].info, info );

    }

    qsort( logs, numLines, sizeof( Log ), &compareByDateTime );

    int id = getMostSleepyGuard( logs, numLines );
//    printf( "Most likely guard to fall asleep is ID #%d\n", id );
    int pos = getMostSleptMinute( id, logs, numLines );
//    printf( "Most common minute slept is %d\n", pos );
    printf( "ID of most frequently asleep guard * minute most asleep (Q4 Part "
            "1): %d\n", id * pos );

    int ans2 = getMostSleepyMethod2( logs, numLines );
    printf( "ID of guard most frequently asleep on a minute * that minute (Q4"
            " Part 2): %d\n", ans2 );
}




int getMostSleepyGuard( Log *logs, int numLines )
{
    int index = 0, startTime = 0, endTime = 0, shiftSleep = 0;
    HashTable *ht = createHashTable( TABLE_SIZE );
    for ( int ii = 0; ii < numLines; ii++ )
    {
        if ( *logs[ii].info == 'G' )
        {
            sscanf( logs[ii].info, "Guard #%d %*50[^\n]", &index );
            shiftSleep = 0;
        }
        else if ( *logs[ii].info == 'f' )
        {
            startTime = logs[ii].time.minute;
        }
        else if ( *logs[ii].info == 'w' )
        {
            endTime = logs[ii].time.minute;
            int duration = endTime - startTime;
            shiftSleep += duration;
//            printf( "Guard slept for %d minutes.\n", duration );

            if ( ii + 1 < numLines && *logs[ii + 1].info == 'G' )
            {
//                printf( "Guard %d slept for %d minutes on shift.\n", index,
//                        shiftSleep );
                int length = snprintf( NULL, 0, "%d", index );
                char *str = ( char * ) malloc(
                        sizeof( char ) * ( length + 1 ) );
                snprintf( str, length + 1, "%d", index );
                incrementValue( ht, str, shiftSleep );
                free( str );
            }
        }
    }
    char *ptr;
    int id = strtol( getMostCommonKey( ht ), &ptr, 10 );
    destroyHashTable( ht );

    return id;
}




int getMostSleptMinute( int id, Log *logs, int numLines )
{
    bool valid = false;
    int mostCommonMinute[60];
    memset( mostCommonMinute, 0, 60 * sizeof( int ) );
    int startTime = 0, endTime = 0, index = 0;
    for ( int ii = 0; ii < numLines; ii++ )
    {
        if ( *logs[ii].info == 'G' )
        {
            sscanf( logs[ii].info, "Guard #%d %*50[^\n]", &index );
            if ( index == id )
            {
                valid = true;
            }
            else
            {
                valid = false;
            }
        }
        else if ( valid )
        {
            if ( *logs[ii].info == 'f' )
            {
                startTime = logs[ii].time.minute;
            }
            else if ( *logs[ii].info == 'w' )
            {
                endTime = logs[ii].time.minute;
                for ( int jj = startTime; jj < endTime; jj++ )
                {
                    mostCommonMinute[jj] += 1;
                }
            }
        }
    }
    int mostSleptMinute = getMaxValue( mostCommonMinute );
    return mostSleptMinute;
}




int getMaxValue( const int *mostCommonMinute )
{
    int largest = -1, pos = -1;
    for ( int ii = 0; ii < 60; ii++ )
    {
        if ( mostCommonMinute[ii] > largest )
        {
            largest = mostCommonMinute[ii];
            pos = ii;
        }
    }
    return pos;
}




int populateGuardHT( HashTable *ht, int size, Log *logs, int numLines )
{
    int index = 0, startTime = 0, endTime = 0;
    for ( int ii = 0; ii < numLines; ii++ )
    {
        if ( *logs[ii].info == 'G' )
        {
            sscanf( logs[ii].info, "Guard #%d %*50[^\n]", &index );
        }
        else if ( *logs[ii].info == 'f' )
        {
            startTime = logs[ii].time.minute;
        }
        else if ( *logs[ii].info == 'w' )
        {
            endTime = logs[ii].time.minute;
            for ( startTime; startTime < endTime; startTime++ )
            {
                int length = snprintf( NULL, 0, "%d", index );
                char *str = ( char * ) malloc(
                        sizeof( char ) * ( length + 4 ) );
                // 4 chars longer for the +(minute) chars
                snprintf( str, length + 4, "%d+%d", index, startTime );
                incrementValue( ht, str, 1 );
                free( str );
            }
        }
    }
}




int getMostSleepyMethod2( Log *logs, int numLines )
{
    int size = 60 * TABLE_SIZE;
    HashTable *ht = createHashTable( size );
    populateGuardHT( ht, size, logs, numLines );
    char *key = getMostCommonKey( ht );
    int result = 0;
    char *p;
    p = strtok( key, "+" );

    if ( p )
    {
        char *ptr;
        int a = strtol( p, &ptr, 10 );
        p = strtok( NULL, "+" );
        if ( p )
        {
            int b = strtol( p, &ptr, 10 );
            result = a * b;
        }
    }
    destroyHashTable( ht );
    free( logs );
    return result;
}