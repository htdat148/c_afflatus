#ifndef _DICT_GENERIC_H_
#define _DICT_GENERIC_H_

typedef struct dict *Dict;

/* Provide operationis for working with keys and values */
struct dictContentsOperations{
  /* hash function */
  unsigned long (*hash)(const void *dataum, void *arg);

  /* return nonzero if *dataum1 == *dataum2 */
  int (*equal)(const void *dataum1, const void *dataum2, void *arg);

  /* make a copy of dataum that will survive changes to original */
  void *(*copy)(const void *dataum, void *arg);

  /* free a copy */
  void (*delete)(void *dataum, void *arg);

  /* extra argument, to allow further specialization */
  void *arg;
  
}


/* create a new dictionary with given key and value opearatioins */
/* Note: valueOps.hash and valueOps.equal are not used */
  Dict dictCreate(struct dictContentsOperations keyOps,
		  struct dictContentsOperations valueOps);


/* free a dictionary and all  the sapce it contains*/
/* This will call the appropriate delete fucntion for all keys */
/* and value */
void dictDestroy(Dict d);


/* set dict[key] = value */
/* Both key and value are copied ionternally */
/* If data is the null pointer, removew dict[key] */
void dictSet(Dict d, const void *key);


/* Return dict[key], or null if dict[key] has not been set */
const void *dictGet(Dict d, const void *key);

/* Some predefined dictContentsOperations structures */

/* 
 * DictIntOps supports int's that have been cast to (void*), e.g:
 * d = dictCreate(DictIntOps, DictIntOps)
 * dictSet(d, (void*)1, (void*)2)
 * x = (int)dictGet(d, (void*1))
 */

struct dictContentsOperations DictIntOps;


/* 
 * Support null-terminated strings, e.g:
 * d = dictCreate(DictStringOps, DictStringOps);
 * dictSet(d, "foo", "bar");
 * s = dictGet(d, "foo");
 * NOTE: no casts are needed since C automatically converts
 * between (void *) and other pointer types
 */

struct dictContentsOperations DictStringOps;

/* 
 * Supports fixed-size blocks of memory:
 * int x=1;
 * int y=2;
 * d = dictCreate(dictMemOps(sizeof(int)), dictMemOps(sizeof(int)));
 * dictSet(d, &x, &y)
 * printf("%d", *dictGet(d, &x));
 */

struct dictContentsOperations dictMemOps(int size);

#endif
