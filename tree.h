/*
 * General tree implementation in c.
 * The children nodes, they are also tree, stored in array list structure.
 * 
 * Author: Batuhan BASAK.
 */
#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 5

typedef struct tree{
    // The data of tree.
    int data; 
    // The list of child nodes.
    struct tree **children; 
    // The size of children array list.
    int size; 
    // The capacity of children array list.
    int capacity; 
}tree_t;


/* init_tree: Initialize a tree and returns address of it.
 * data: The data of tree.
 */
tree_t *init_tree(int data);



/* delete_tree: Deletes given tree.
 * tp: The pointer holds the address of tree pointer.
 */
void delete_tree(tree_t **tp);



/* get: Returns the data of given tree
 * t: The tree
 */
int get(const tree_t *t);



/* set: Sets the given data to data of given tree.
 * t: The tree.
 * data: The data to set to.
 */
int set(tree_t *t, int data);


/* addChild: Adds given child node to given tree.
 * t: The tree to add on it.
 * c: The child node to add it.
 */
void addChild(tree_t *t, tree_t *c);



/* removeChild: Removes a child which is at given position in children list
 *              of given tree.
 * t: The tree to remove from.
 * index: The position of child node to remove.
 */
tree_t *removeChild(tree_t *t, int index);


/* indexOfChild: Finds the index of given child node in given tree.
 * t: The tree being searched on it.
 * c: The child being searched on. 
 * Returns index of target child node in children array.
 * If target child node doesn't exist in tree returns -1.
 */
int indexOfChild(tree_t*, tree_t *c);


/* getChild: Returns the child node at the given specific position in 
 *           children array of given tree.
 * t: The tree to search on it.
 * index: The position of child node.
 */
tree_t *getChild(tree_t *t, int index);


// Reallocates children list of given tree to increase the array list size.
void reallocateChildren(tree_t *t);

/* printTree: Prints given tree in tree structure. Function traverse and prints
 *            tree from root to each leaf.
 * t: The tree to print it.
 */
void printTree(tree_t *t);

// The helper function for printTree function.
void _printTree(tree_t *t, int lvl);



#endif
