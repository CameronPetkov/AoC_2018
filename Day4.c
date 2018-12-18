// FILE: Day4.c
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 15/12/2018
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

    int index = 0;
    HashTable *ht = createHashTable( TABLE_SIZE );
    int startTime = 0, endTime = 0, shiftSleep = 0;
    for ( int ii = 0; ii < numLines; ii++ )
    {
//        printf( "[%d-%02d-%02d %02d:%02d] %s\n", logs[ii].date.year,
//                logs[ii].date.month, logs[ii].date.day, logs[ii].time.hour,
//                logs[ii].time.minute, logs[ii].info );
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
                incrementValue( ht, index, shiftSleep );
            }
        }
    }

    int id = getMostCommonKey( ht );
    printf( "Most likely guard to fall asleep is ID #%d\n", id );
    destroyHashTable( ht );

    bool valid = false;
    int mostCommonMinute[60];
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
                for ( int ii = startTime; ii < endTime; ii++ )
                {
                    mostCommonMinute[ii] += 1;
                }
            }
        }
    }

    int largest = 0, pos = 0;
    for ( int ii = 0; ii < 60; ii++ )
    {
        if ( mostCommonMinute[ii] > largest )
        {
            largest = mostCommonMinute[ii];
            pos = ii;
        }
    }

    printf( "Most common minute slept is %d", pos );

    free( logs );
}