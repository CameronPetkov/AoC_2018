// FILE: BinarySearchTree.h
// AUTHOR: Cameron Petkov
// PURPOSE: N/A
// REFERENCE: N/A
// LAST MOD: 8/12/2018
// COMMENTS: 

#ifndef AOC_2018_BINARYSEARCHTREE_H
#define AOC_2018_BINARYSEARCHTREE_H


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>




typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    int size;
} TreeNode;


TreeNode *createNode( int value );
bool insert( TreeNode **node, int value );
bool isEmpty( TreeNode **tree );

#endif
