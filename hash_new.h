/* 
 * 
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#ifndef H_HASH
#define H_HASH

#define INITIAL_TABLE_LEN 11

/* initialize the hash table */
int initialize(void ***array, int *sizeptr);

/* find the hash code of string using a standard function */
int hashcode(char *s);

/* print the hash table */
void printTable(void *array[], int count);

/* insert a string s to the hash table. Return 1 if there is collision */
/* Else return 0 */
int add(void *A[], char *s, int *size);

/* delete an element in the hash table. Return 1 if the element does not exit */
/* else return 0 */
int delete(void *hashTable[], char *s);

/* resize the hash table if full. Need to rehash all elements */
int resize(void ***arrayptr, int *sizeptr);

/* clear the hash table */
int clear(void ***hashTable);


#endif
