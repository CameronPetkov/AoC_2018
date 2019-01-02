// FILE: HashTable.c
// AUTHOR: Cameron Petkov
// PURPOSE:
// REFERENCE:
// LAST MOD: 02/01/2019
// COMMENTS: 

#include "HashTable.h"




HashTable *createHashTable( int size )
{
    HashTable *table = ( HashTable * ) malloc( sizeof( HashTable ) );

    table->length = 0;
    table->size = size;
    table->indexes = ( LinkedList ** ) malloc( size * sizeof( LinkedList * ) );
    for ( int ii = 0; ii < size; ii++ )
    {
        table->indexes[ii] = createLinkedList();
    }

    return table;
}




void destroyHashTable( HashTable *table )
{
    int size = table->size;
    for ( int ii = 0; ii < size; ii++ )
    {
        clear( table->indexes[ii] );
        free( table->indexes[ii] );
    }
    free( table->indexes );
    free( table );
}




void insertHT( HashTable *table, char key[], int data )
{
    DataItem *item = ( DataItem * ) malloc( sizeof( DataItem ) );
    item->key = key;
    item->data = data;

    int index = hashCode( key );
    if ( isEmptyLL( table->indexes[index] ) )
    {
        insertFirst( table->indexes[index], item );
    }
    else
    {
        insertLast( table->indexes[index], item );
    }
    table->length += 1;
}




DataItem *search( HashTable *table, char key[] )
{
    DataItem *item = NULL;
    int index = hashCode( key );

    if ( table->indexes[index]->length == 0 )
    {

    }
    else if ( !isEmptyLL( table->indexes[index] ) )
    {
        for ( int ii = 0; ii < table->indexes[index]->length; ii++ )
        {
            DataItem *tempItem = get( table->indexes[index], ii );
            if ( strncmp( tempItem->key, key, strlen( key ) ) == 0 )
            {
                item = tempItem;
            }
        }
    }
    return item;
}




//FNV-1a
int hashCode( char key[] )
{
    uint32_t hash = SEED;

    for ( int ii = 0; ii < strlen( key ); ii++ )
    {
        hash = ( hash ^ key[ii] ) * PRIME;
    }

    int index = ( int ) ( hash % TABLE_SIZE );
    if ( index < 0 )
    {
        index *= -1;
    }

    return index;
}




void incrementValue( HashTable *table, char key[], int data )
{
    DataItem *item = search( table, key );
    if ( item == NULL )
    {
//        printf( "New guard!\n" );
        insertHT( table, key, data );
    }
    else
    {
//        printf( "Old guard!\n" );
        item->data += data;
    }
}




void display( HashTable *table )
{
    for ( int ii = 0; ii < table->size; ii++ )
    {
        if ( table->indexes[ii]->length != 0 )
        {
            printf( "Index %d: ", ii );
            for ( int jj = 0; jj < table->indexes[ii]->length; jj++ )
            {
                DataItem *item = ( DataItem * ) get( table->indexes[ii], jj );
                printf( "Key/ID: %s, Value: %d       ", item->key, item->data );
            }
            printf( "\n" );
        }
        else
        {
            printf( "Index %d: Empty slot!\n", ii );
        }
    }
}




char *getMostCommonKey( HashTable *table )
{
    int key = 0, maxValue = 0;
    for ( int ii = 0; ii < table->size; ii++ )
    {
        if ( table->indexes[ii]->length != 0 )
        {
            for ( int jj = 0; jj < table->indexes[ii]->length; jj++ )
            {
                DataItem *item = ( DataItem * ) get( table->indexes[ii], jj );
                if ( item->data > maxValue )
                {
                    key = item->key;
                    maxValue = item->data;
                }
            }
        }
    }
    return key;
}