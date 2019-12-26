#ifndef _DEQUE_H_
#define _DEQUE_H_

#define DEQUE_FRONT (0)
#define DEQUE_BACK (1)

/* return by dequepop if deque is empty */
#define DEQUE_EMPTY (-1)

typedef struct deque Deque;

/* return a new empty deque */
Deque *dequeCreate(void);


/* push a new value onto direction side of deque d */
void dequePush(Deque *d, int direction, int value);

/* pop and return first value on direction siode of dequeu d */
/* return DEQUE_EMPTY if deque is emptyu */
int dequePop(Deque *d, int direction);

/* return 1 if deque contain no elementsm, 0 otherwise */
int dequeIsEmpty(const Deque *d);

/* free space used by a deque */
void dequeDestroy(Deque *d);

#endif
