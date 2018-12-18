// FILE: HashTable.h
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 18/12/2018
// COMMENTS: 

#ifndef AOC_2018_HASHTABLE_H
#define AOC_2018_HASHTABLE_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#include "LinkedList.h"
#include "Day4.h"




#define PRIME 0x01000193

#define TABLE_MAX_PF 0.65


typedef struct DataItem
{
    int key;
    int data;
} DataItem;

typedef struct HashTable
{
    int length;
    int size;
    LinkedList **indexes;
} HashTable;

//struct LinkedList *hashArray[TABLE_SIZE];


HashTable *createHashTable( int size );
void destroyHashTable( HashTable *table );
void insertHT( HashTable *table, int key, int data );
DataItem *search( HashTable *table, int key );
int hashCode( int key );
void incrementValue( HashTable *table, int key, int data );
void display( HashTable *table );
int getMostCommonKey( HashTable *table );

#endif //AOC_2018_HASHTABLE_H
