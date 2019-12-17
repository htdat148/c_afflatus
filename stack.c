#include "stack.h"


struct node*  StackInit(struct node* head){
  head = NULL;
  return head;
};

struct node* StackPush(struct node* head, int data){
  struct node* newNode = (struct node *)malloc(sizeof(struct node));
  assert(newNode);
  
  newNode->data = data;
  newNode->next = head;

  head = newNode;
  return head;
  
};

void StackDestroy(struct node* head){
  struct node* nextNode;

   
  while (head != NULL){
    nextNode = head->next;
    free(head);
    head = nextNode;

    
  }
  printf("\nStack's memory is free\n");
};




struct node* StackPop(struct node* head, int *element){
  *element = head->data;
  struct node* currentNode = head;
  free(currentNode);

  return( head->next);
};


void StackIsEmpty(struct node* head){
  if(head != NULL)
    printf("\nStack not empty\n");
  else
    printf("\nStack empty\n");
};
