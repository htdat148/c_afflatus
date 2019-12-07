#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node{
  int data;
  struct node *next;
};


/* create the linked list */
/* element = 3 */
/* linked list creted {0,1,2} */
void createLinkedList(struct node **head, int elements);

/* print all elements in the list */
void printList(struct node *head);

/*  count the number of times a given number occurs in a list*/
int count(struct node *head, in searchFor);

/* get the data value stored in the node at that index position */
/* list {1,2,3} */
/* index = 2 return value 3 */
int GetNth(struct node *head, int index);

/* deallocaes all of its memory and set head pointer to NULL */
void DeleteList(struct node **headRef);

/* delete the head node and return the head node's data */
int Pop(struct node **headRef);

/* get the total number of nodes */
int lengthList(struct node *head);

/* insert a new node to the the index position */
/* InsertNth(&head, 0, 13); // build {13) */
/* InsertNth(&head, 1, 42); // build {13, 42} */
/* InsertNth(&head, 1, 5); // build {13, 5, 42} */
void InsertNth(struct node **headRef, int index, int data);

/* a given list that is sorted in increasing order */
/* insert the node into the correct sorted position in the list */
void SortedInsert(struct node **headRef, int data);

/* rearrangeits node in increasing order */
void InsertSort(struct noe *headRef);

/* append 'b' onto the end of 'a' */
void Append(struct node **aRef, struct node **bRef);

/* split the list into two sublists - one for the front half, and one for the back half */
/* if the elemnets is odd, the extra element should go in the front list */
void FrontBackSplit(struct node *source, struct node **frontRef,
		    struct node **backRef);

/* delete any duplicate nodes from the list */
void RemoveDuplicate(struct node **head);

/* reverse all elements in list */
void Reverse(struct node **headRef);

#endif
