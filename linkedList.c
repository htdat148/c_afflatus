#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


void createLinkedList(struct node **head, int elements){
  int count;
  struct node *currentNode;
  /* wrong way */
  /* currentNode =*head; */
  /* currentNode = (struct node*)malloc(sizeof(struct node)); */
  *head = (struct node*)malloc(sizeof(struct node));
  currentNode = *head;
  currentNode->data = 0;
  for(count=1; count < elements; count++){
    
    currentNode->next = (struct node *)malloc(sizeof(struct node));
    currentNode->next->data = count;
    currentNode = currentNode->next;
  }
  currentNode->next = NULL;
}


void printList(struct node *head){
  if(head == NULL){
    printf("No list elements\n");
    return;
  }

  while(head != NULL){
    printf("%d\n", head->data);
    head = head->next;
  }
}

/* 1--Count() */
int count(struct node* head, int searchFor){
  int count=0;
  
  while(head != NULL){
    if (head->data == searchFor)
      count++;

     head = head->next;
  }
  return count;
  
}

int GetNth(struct node* head, int index){
  int count;
  for (count=0; count <index; count++){
    head = head->next;
  }
  return head->data;
}

void DeleteList(struct node** headRef){
  struct node* currentNode;
  
  while(*headRef != NULL){
    currentNode = *headRef;
    *headRef = (*headRef)->next;
    free(currentNode);
    currentNode = NULL;
  }
}

int Pop(struct node** headRef){
  struct node* currentNode = *headRef;
  if (currentNode == NULL)
    return -1;
  int data = currentNode->data;
  *headRef = (*headRef)->next;
  free(currentNode);
  return data;
  
}

int lengthList(struct node *head){
  int count=0;
  while(head != NULL){
    head = head->next;
    count++;
  }
  return count;
}


void InsertNth(struct node **headRef, int index, int data){
  struct node *nodeLength;
  nodeLength = *headRef;
  int length = lengthList(nodeLength);
  if (index > length){
    printf("Not correct");
    return;
  }
  if(*headRef == NULL && index > 0)
    return;
  else if (*headRef == NULL && index == 0){
    *headRef = (struct node*)malloc(sizeof(struct node));
    (*headRef)->data = data;
    (*headRef)->next = NULL;
    return;}

  else if(*headRef != NULL && index == 0){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
    return;
  }

  else{
    int count;
    struct node *currentNode = *headRef;
    struct node *nextNode, *prevNode;
       
    for(count = 0; count < index; count++){
      prevNode = currentNode;
      currentNode = currentNode->next;
      
    }
      

    if (currentNode == NULL){
      currentNode = (struct node*)malloc(sizeof(struct node));
      currentNode->data = data;
      currentNode->next = NULL;
      prevNode->next = currentNode;
      return ;
    }

    else{
      prevNode->next = (struct node*)malloc(sizeof(struct node));
      prevNode->next->data = data;
      prevNode->next->next = currentNode;
      return;
    }
       
  }
       
}

void SortedInsert(struct node **headRef, int data){
  
  if(*headRef == NULL){
    *headRef = (struct node *)malloc(sizeof(struct node));
    (*headRef)->data = data;
    (*headRef)->next = NULL;
    return;
  }

  
  struct node *tempNode = (struct node*)malloc(sizeof(struct node));  
  tempNode->data = data;
  tempNode->next = NULL;

  if(data <= (*headRef)->data){
    tempNode->next = (*headRef);
    (*headRef) =  tempNode;
    return ;
  }

  struct node *nextNode;
  struct node *currentNode;

  for(currentNode=*headRef; currentNode != NULL; currentNode=currentNode->next){
    if(data >= currentNode->data && currentNode->next == NULL){
      currentNode->next = (struct node *)malloc(sizeof(struct node));
      currentNode->next->data = data;
      currentNode->next->next = NULL;
      return;
    }
    
    else if(data >= currentNode->data && data <= currentNode->next->data){
      nextNode = currentNode->next;
      currentNode->next = tempNode;
      tempNode->next = nextNode;
      return;
	}
  }
  
  
  
  return;
}

void InsertSort(struct node **headRef){
  struct node* temp1, *temp2;

  int temp;

  for(temp1=*headRef; temp1 !=NULL; temp1= temp1->next)
    {
      for(temp2= temp1->next; temp2!=NULL; temp2=temp2->next){
	if(temp2->data < temp1->data){
	  temp = temp1->data;
	  temp1->data = temp2->data;
	  temp2->data = temp;
	}
      }
    }
}

/* Append 'b' onto the end of 'a' and then set 'b' to NULL */
void Append(struct node **aRef, struct node **bRef){
  struct node *headA;
  struct node *headB;
  struct node *currentNode, *prevNode;

  currentNode = *aRef;
  while(currentNode != NULL){
    prevNode = currentNode;
    currentNode = currentNode->next;
  }

  prevNode->next = *bRef;
  return;
  
}


void FrontBackSplit(struct node *source, struct node **frontRef,
		    struct node **backRef){

  int length = lengthList(source);
  int lengthFront;
  int lengthBack;

  if(length < 2)
    return;
  
  if(length % 2 == 0)
    lengthFront = lengthBack = length/2;
  else{
    lengthFront = length/2 +1;
    lengthBack = length-lengthFront;
  }
  
  printf("\nlenFront: %d - lenBack: %d\n", lengthFront,lengthBack);

  int index;
  struct node *sourceNode = source;
  
  /* copy to frontRef */
  struct node *frontNode;
  *frontRef = (struct node *)malloc(sizeof(struct node));
  frontNode = *frontRef;  
  frontNode->data = sourceNode->data;
    
  for(index=1; index<lengthFront; index++){
    frontNode->next = (struct node *)malloc(sizeof(struct node));
    
    sourceNode = sourceNode->next;
    frontNode->next->data = sourceNode->data;
    frontNode = frontNode->next;
  }
  frontNode = NULL;

  
  /* copy to backRef */
  sourceNode = sourceNode->next;
  struct node *backNode;
  *backRef = (struct node *)malloc(sizeof(struct node));
  backNode = *backRef;  
  backNode->data = sourceNode->data;
    
  for(index=1; index<lengthBack; index++){
    backNode->next = (struct node *)malloc(sizeof(struct node));
    
    sourceNode = sourceNode->next;
    backNode->next->data = sourceNode->data;
    backNode = frontNode->next;
  }
  backNode = NULL;
  
  /* /\* copy frontRef *\/ */
  /* *frontRef = (struct node *)malloc(sizeof(struct node)); */
  /* struct node *frontNode = *frontRef; */
  /* frontNode->data = sourceNode->data; */
  /* frontNode = frontNode->next; */
  /* sourceNode = sourceNode->next; */

  /* for(index=1; index<lengthFront; index++){ */
  /*   frontNode = (struct node *)malloc(sizeof(struct node)); */
  /*   frontNode->data = sourceNode->data; */
  /*   frontNode = frontNode->next; */
  /*   sourceNode= sourceNode->next; */
  /* } */
  /* frontNode->next = NULL; */

  /* /\* copy to backRef *\/ */
  /* *backRef = (struct node *)malloc(sizeof(struct node)); */
  /* struct node *backNode = *backRef; */
  /* backNode->data = sourceNode->data; */
  /* backNode = backNode->next; */
  /* sourceNode = sourceNode->next; */


  /* for(index=1; index<lengthBack; index++){ */
  /*   backNode = (struct node *)malloc(sizeof(struct node)); */
  /*   backNode->data = sourceNode->data; */
  /*   backNode = backNode->next; */
  /*   sourceNode= sourceNode->next; */
  /* } */
  /* backNode->next = NULL; */
}



void RemoveDuplicate(struct node ** head){
  struct node *prevNode, *currentNode, *nextNode;

  int data;
  
  for(currentNode = *head; currentNode != NULL; currentNode=currentNode->next){
    data = currentNode->data;

    for(nextNode = currentNode->next; nextNode != NULL; nextNode = nextNode->next){

      /* deletect duplicate */
      if(data == nextNode->data && currentNode->next == nextNode)
	currentNode->next = nextNode->next;
            
      else if (data == nextNode->data)
	prevNode->next=nextNode->next;
      else
	prevNode = nextNode;
    }
  }
}

void Reverse(struct node **headRef){
  struct node *headReverse = (struct node*)malloc(sizeof(struct node));
  headReverse->data = (*headRef)->data;
  headReverse->next = NULL;
  
  struct node *currentNode;
 

  for( currentNode = (*headRef)->next; currentNode != NULL; currentNode=currentNode->next){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = currentNode->data;
    newNode->next = headReverse;
    headReverse = newNode;
  }
  DeleteList(headRef);
  *headRef = headReverse;
  
}
