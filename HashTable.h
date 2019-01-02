// FILE: HashTable.h
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 02/01/2019
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
#define SEED 0x811C9DC5

#define TABLE_MAX_PF 0.65


typedef struct DataItem
{
    char *key;
    int data;
} DataItem;

typedef struct HashTable
{
    int length;
    int size;
    LinkedList **indexes;
} HashTable;


HashTable *createHashTable( int size );
void destroyHashTable( HashTable *table );
void insertHT( HashTable *table, char key[], int data );
DataItem *search( HashTable *table, char key[] );
int hashCode( char key[] );
void incrementValue( HashTable *table, char key[], int data );
void display( HashTable *table );
char *getMostCommonKey( HashTable *table );

#endif //AOC_2018_HASHTABLE_H
