#ifndef _STACK_H_
#define _STACK_H_


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/* define the node */
/* create stack with linked list */
/* LIFO --- Last In First Out */
struct node{
  itn data;
  struct node *next;
}

void        StackInit(struct node* head);
void StackDestroy(struct node*head);

void        StackPush(struct node* head, int dat);
int StackPop(struct node* head);
int StackIsEmpty(struct node* head);


#endif
