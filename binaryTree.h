#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

struct node{
  int data;
  struct node* left;
  struct node* right;
};

/* create a new node */
struct node* NewNode(int data);

/* insert a given data to the gevin tree */
struct node* insert(struct node* root, int data);

/* two ways to create a tree with 3 node */
/*    2 */
/*   / \  */
/*  1   3 */
struct node* build123();

/* count the number of nodes in the tree*/
int size(struct node *node);

/* maxDepth -- the number of nodes along te logest patch */
/* from the root node down to the farthest leaf node */
int maxDepth(struct node *node);


/* given an non-empty binary search tree */
/* return the minumum data value found it tthat tree */
int minValue(struct node *node);


             /*   4     */
             /*  / \    */
             /*  2  5   */
             /* / \     */
          /*   1   3    */
/* iterate over the nodes to print them out in increasing oreder */
/* outpu: 1-2-3-4-5 */
void printTree(struct node* node);
