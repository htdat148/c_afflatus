/* Queue --- FIFO First In First Out */

/* Enquere a new element typlically require allocating a new struct to hold it, */
/* making the old node point at the new struct */
/* Updating the tail pointer to aslo point to the new struct */

/* Dequeue an element invoke updating the head pointer and freeing the removed struct, exactly like a stack pop */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* standart linked list element */
struct elt{
  int data;
  struct elt* next;
};

struct queue{
  struct elt *head;		/* dequeue this next */
  struct elt *tail;		/* enquere after this */
};

/* create a new empty queue */
struct queue* queueCreate(void){
  struct queue *q = (struct queue *)malloc(sizeof(struct queue));

  q->head = q->tail = NULL;
  return q;
};

/* add a new value to back or queue */
void enq(struct queue *q, int value){
  struct elt *newElt;
  newElt = (struct elt *)malloc(sizeof(struct elt));
  /* newElt is the tail */
  /* next will be NULL */
  
  newElt->data = value;
  newElt->next = NULL;
  /* when the queue is empty */
  if(q->head == NULL)
    q->head = q->tail = newElt;
  /* queue has element */
  else{
    q->tail->next = newElt;
    q->tail = newElt;

  }
};

/* check queue is empty or not */
int IsQueueEmpty(const struct queue *q){
  if(q->head != NULL)
    return 0;
  else
    return 1;
}

/* remove and return value from front of queue */
int deq(struct queue *q){
  assert(!IsQueueEmpty(q));
  int data;
  struct elt *nextElt;
  nextElt = q->head->next;
  data = q->head->data;
  
  free(q->head);
  q->head = nextElt;
  return data;
  
};


/* print contents of queue on a single line, head first */
void queuePrint(struct queue *q){
  struct elt * currentElt;
  assert(!IsQueueEmpty(q));
  printf("\n");
  for(currentElt = q->head; currentElt != NULL; currentElt = currentElt->next)
    printf("%d", currentElt->data);
   printf("\n");
};

/* free a queue and all its elements */
void queueDestroy(struct queue *q){
  struct elt * currentElt;
  assert(!IsQueueEmpty(q));
  
  while(q->head != NULL){
    currentElt = q->head;
   
    q->head = currentElt->next;
    free(currentElt);
     
  }
  return;
};



int
main(int argc, char **argv)
{
  int i;
  struct queue *q;
  q = queueCreate();
  for(i = 0; i < 5; i++) {
    printf("enq %d\n", i);
    enq(q, i);
    queuePrint(q);
  }
  while(!IsQueueEmpty(q)) {
    printf("deq gets %d\n", deq(q));
    queuePrint(q);
  }
  queueDestroy(q);
  return 0;
}
