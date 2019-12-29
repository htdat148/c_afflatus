#ifndef _IDLIST_H_
#define _IDLIST_H_


/* A low-overhead hash table using open addressing */
typedef struct idList *IDList;

#define MIN_ID (0)
#define MAX_ID (99999999)

/* build an IDList out of an unsorte array of n good ids */
/* returns 0 on allacation failture */

IDList IDListCreate(int n, int unsortedIdList[]);

/* destriy an IDList */
void IDListDestroy(IDList list);

/* check an id against the list */
/* return nonzero if id is in the list */
int IDListContains(IDList list, int id);

#endif
