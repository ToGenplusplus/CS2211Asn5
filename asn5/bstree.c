#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
/**
 *Temi Owoaje, 250980280
 *Bstree.c file.
 *
 * */


void bst_insert(BStree_node **node_ptr, Key key, Data data);
BStree_node *new_node(Key key, Data data);

//initialize a binary search tree.
BStree bstree_ini(void)
{
	BStree bst;
 	bst = (BStree)malloc( sizeof(BStree_node*));// allocate memory of size Bstree_node*
 	*bst = NULL;
 	return bst; // returns pointer to allocation

}

// helper funtion to insert node into tree
void bst_insert(BStree_node **node_ptr, Key key, Data data)
{
	if ( *node_ptr == NULL )// check if node in tree is free,if its null its free. 
	{
		*node_ptr = new_node(key,data);// insert new node into tree
	}
	else
	{
	int keycomp = key_comp(key, (*node_ptr)->key);// compare newkey, with key already inside tree
	if ( keycomp  < 0 )
                {
                        bst_insert(&(*node_ptr)->left, key, data);// traverse left side of tree if keycomp returns a key less than 0.
                }
        else if ( keycomp  > 0 )
                {
                        bst_insert(&(*node_ptr)->right, key, data);// traverse right side.

                }
	}
}
// function calls helper function and adds node to a binary search tree.
void bstree_insert(BStree bst, Key key, Data data)
{

        bst_insert(bst,key,data);

}


//helper function for insertion to create a pointer to a tree node from
//key and data.
BStree_node *new_node(Key key, Data data)
{

	BStree_node *nnode;
	nnode =(BStree_node *)malloc(sizeof(BStree_node *));// alocate memory for the new node.
	(*nnode).key = key;
	(*nnode).data= data;
	(*nnode).left = NULL;
	(*nnode).right = NULL;

	return nnode;
	free(nnode); // free all memory used by newn node( so dont have to free later)
}
// function searches a binary search tree for a key, if key in tree return the keys data.Otherwise return NULL.
Data bstree_search(BStree bst, Key key)
{

	if ( *bst == NULL ) {
                
		return NULL;
		
        }
        else
        {
		int keycomp = key_comp(key, (*bst)->key);
        	//printf("%d\n", keycomp);
        	//printf("%d\n",(*bst)->data);
                if ( keycomp > 0 )
                {
                        bstree_search(&(*bst)->right, key);
                }
                else if( keycomp  <  0 )

                {
                      	bstree_search(&(*bst)->left, key);

                }
		else
		{
			return (*bst)->data;
		}
        }


}

// helper function to traverse tree and print each nodes key and data.
static void btree_traversal(BStree_node *bt) {
 	if ( bt == NULL ) return;

	btree_traversal(bt->left);// first access left side of node.

	key_print(bt->key);

	data_print(bt->data);

	btree_traversal(bt->right);// then access right side of node


}


void bstree_traversal(BStree bst)
{

	if (bst == NULL)
	{
		return;
	}
	btree_traversal(*bst);
	
}

// function to free all memory used by BST.



void bstree_free(BStree bst)
{

free(bst);// free root

}
