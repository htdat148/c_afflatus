/* A string to string dictionary chaining */

#ifndef _DICT_H_
#define _DICT_H_

typedef struct dict *Dict;

/* create a new empty dictionary */
Dict DictCreate(void);

/* Destroy a dictionary */
void DictDestroy(Dict);

/* insert a new key-value pair into an existing dictionary */
void DictInsert(Dict, const char *key, const *value);

/* return the most recently inserted value associated with a key */
/* or 0 if no matching key is present */
const char *DictSearch(Dict, const char *key);


/* delete the most recenctly inserted record with the given key */
/* if there is no such record, has no effect */
void DictDelete(Dict, const char *key);


#endif
