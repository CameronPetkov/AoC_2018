// FILE: BinarySearchTree.h
// AUTHOR: Cameron Petkov
// PURPOSE: N/A
// REFERENCE: N/A
// LAST MOD: 9/12/2018
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
} TreeNode;


void createNode( TreeNode **root, int value );
bool insert( TreeNode **node, int value );
void clearTree( TreeNode **node );

#endif
