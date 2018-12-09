// FILE: BinarySearchTree.c
// AUTHOR: Cameron Petkov
// PURPOSE: Allow creation and manipulation of BST
// REFERENCE: http://www.zentut.com/c-tutorial/c-binary-search-tree/
//            https://stackoverflow.com/a/33715699
// LAST MOD: 9/12/2018
// COMMENTS: 

#include "BinarySearchTree.h"




void createNode( TreeNode **root, int value )
{
    if ( *root == NULL )
    {
        fprintf( stderr, "Error: Memory not assigned!\n" );
    }
    else
    {
        ( *root )->data = value;
        ( *root )->left = NULL;
        ( *root )->right = NULL;
    }
}




bool insert( TreeNode **node, int value )
{
    bool isFound = false;
    if ( *node == NULL )
    {
        TreeNode *newNode = ( TreeNode * ) malloc( sizeof( TreeNode ) );
        createNode( &newNode, value );
        *node = newNode;
    }
    else
    {
//        printf( "Value: %d\n", value );
//        printf( "Parent: %d\n\n", ( *node )->data );
        if ( ( *node )->data == value )
        {
            printf( "Duplicate found (Q1 Part 2): %d\n", value );
            isFound = true;
        }
        else if ( ( *node )->data > value )
        {
            isFound = insert( &( *node )->left, value );
        }
        else if ( ( *node )->data < value )
        {
            isFound = insert( &( *node )->right, value );
        }
    }

    return isFound;
}




bool isEmpty( TreeNode **tree )
{
    return ( ( *tree == NULL ) );
}




void clearTree( TreeNode **node )
{
    if ( *node != NULL  )
    {
//        printf("Trying to free nodes\n");
        clearTree( &(*node)->left );
        clearTree( &(*node)->right );

        free( *node );
    }
}