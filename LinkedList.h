/* FILE: linkedList.c
 * AUTHOR: Cameron Petkov
 * UNIT: Unix and C Programming
 * PURPOSE: Contains all functions that get implement a linked list
 * REFERENCE: None
 * LAST MOD: 18/12/2018
 * COMMENTS: None
 */

#ifndef AOC_2018_LINKEDLIST_H
#define AOC_2018_LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "LinkedList.h"




/* NAME: LLNode
 * PURPOSE: Act as a node that holds the data desired, and two pointers to
 *          traverse to a previous or the next item. Essentially acts as half
 *          a linked list, which can be implemented with the LinkedList
 *          structure, and appropriate methods found in linkedList.c
 * FIELDS:  [ void* ] data: holds a pointer to a void type, allowing the data
 *          to be anything i.e. generic.
 *          [ LLNode* ] next: holds a pointer to another node (like itself)
 *          which is designated as being the next node.
 *          [ LLNode* ] prev: holds a pointer to another node (like itself)
 *          which is designated as being the previous node. This field allows
 *          reverse traversal and makes the LL "doubly linked".
 * REMARKS: LLNode requires the LinkedList structure and methods to manipulate
 *          the structure as required. */

typedef struct LLNode
{

    void *data;
    struct LLNode *next;
    struct LLNode *prev;
} LLNode;


/* NAME: LinkedList
 * PURPOSE: Acts as the other half of the linked list. This structure holds
 *          the address of the first and last nodes, as well as the length
 *          of the amount of nodes stored.
 * FIELDS:  [ LLNode* ] head: holds a pointer to the first node, allowing the
 *          list to be traversed just by having the LinkedList's head.
 *          [ LLNode* ] tail: holds a pointer to the last node. In addition
 *          to letting a user get the last node, combined with a doubly LL,
 *          traversal can occur from the back. Having a tail means the LL
 *          is a double ended LL.
 *          [ int ] length: An optional field that allows updating of the
 *          amount of nodes in the LL, useful for checking if the list is
 *          empty.
 * REMARKS: LinkedList requires the LLNode structure and methods to manipulate
 *          the structure as required. */

typedef struct
{
    LLNode *head;
    LLNode *tail;
    int length;
} LinkedList;


LinkedList *createLinkedList( void );
bool isEmptyLL( LinkedList *list );
bool insertFirst( LinkedList *list, void *value );
bool insertLast( LinkedList *list, void *value );
bool insertBefore( LinkedList *list, void *valueToFind, void *value );
bool insertAfter( LinkedList *list, void *valueToFind, void *value );
void *removeFirst( LinkedList *list );
void *removeLast( LinkedList *list );
bool removeValue( LinkedList *list, void *value );
void *peekFirst( LinkedList *list );
void *peekLast( LinkedList *list );
bool find( LinkedList *list, void *value );
void *get( LinkedList *list, int index );
int getLength( LinkedList *list );
bool outputList( LinkedList *list );
bool clear( LinkedList *list );

#endif //AOC_2018_LINKEDLIST_H
