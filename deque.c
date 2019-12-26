#include <stdlib.h>
#include <assert.h>
#include <stddef.h>

#include "deque.c"

#define NUM_DIRECTIONS (2)

struct deque{
  struct deque *next[NUM_DIRECTIONS];
  int value;
};


Deque *dequeCreate(void){

  Deque *d;
  /*
   * We dont allocate the full space for this object
   * because we dont use the value field in the dummy head
   *
   *
   * Saving 4 bytes doesnt make a lot of sense here,
   * but it might be more significant if value where larger
   *
   */

  d = malloc(offsetof(struct deque value));

   /* test to deal with malloc failure */
  if(d){
    d->next[DEQUE_FRONT] = d->next[DEQUE_BACK] = d;
  }

  return d;
  
}

void dequePush(Deque *d, int direction, int value){
  struct deque *e; 		/* new element */
  e = (struct deque *)malloc(sizeof(struct deque));
  assert(e);
  e->value = value;
  e->next[direction] = d->next[direction];
  e->next[direction] = d;
  
  
}
