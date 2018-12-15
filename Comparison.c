// FILE: Comparison.c
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 15/12/2018
// COMMENTS: 

#include "Comparison.h"




int compareByDateTime( const void *obj1, const void *obj2 )
{
    int sortVal;

    Log *item1 = ( Log * ) obj1;
    Log *item2 = ( Log * ) obj2;

    if ( item1->date.year < item2->date.year )
    {
        sortVal = -1;
    }
    else if ( item1->date.year > item2->date.year )
    {
        sortVal = 1;
    }
    else
    {
        if ( item1->date.month < item2->date.month )
        {
            sortVal = -1;
        }
        else if ( item1->date.month > item2->date.month )
        {
            sortVal = 1;
        }
        else
        {
            if ( item1->date.day < item2->date.day )
            {
                sortVal = -1;
            }
            else if ( item1->date.day > item2->date.day )
            {
                sortVal = 1;
            }
            else
            {
                if ( item1->time.hour < item2->time.hour )
                {
                    sortVal = -1;
                }
                else if ( item1->time.hour > item2->time.hour )
                {
                    sortVal = 1;
                }
                else
                {
                    if ( item1->time.minute < item2->time.minute )
                    {
                        sortVal = -1;
                    }
                    else if ( item1->time.minute > item2->time.minute )
                    {
                        sortVal = 1;
                    }
                    else
                    {
                        sortVal = 0;
                    }
                }
            }
        }
    }

    return sortVal;
}