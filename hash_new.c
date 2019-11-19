#include "hash_new.h"

/* initialize the hash table */

int initialize(void ***arrayptr, int *sizeptr){
  int i;

  *arrayptr = (void **)malloc(sizeof(void *)* INITIAL_TABLE_LEN);
  if (*arrayptr == NULL)
    return 1;

  for (i=0; i< INITIAL_TABLE_LEN; i++){
    (*arrayptr)[i] = NULL;
  }

  *sizeptr = INITIAL_TABLE_LEN;
  return 0 ;
}


/* find the hash code of a string using a standard function */

int hashcode(char *s){
  int sum = s[strlen(s)-1], p=3;
  int i;

  for (i=1; i<strlen(s); i++){
    sum = (s[strlen(s)-i-1]+ p*(sum));
  }
  return sum%3761;
}

/* void print the hash table */
void printTable(void *array[], int count){
  int i=0;
  if (array == NULL){
    printf("Hash table has not been created yet\n");
    return;
  }
    
  
  for (i=0; i<count; i++){
    printf("%d --- %s\n", i, (char *)array[i]);
  }
}

/* insert a string s to hash table. Return 1 if there is a collision.
 * Else return 0
 */
int add(void *A[], char *s, int *size){
  int h;
  h = hashcode(s);

  if(A[h%(*size)] == NULL){
    A[h%(*size)] = (char *)malloc(strlen(s)+1);
    strcpy(A[h%(*size)], s);
    return 0;
  }
  printf("This place already used\n");
  return 1;
}

/* resize the hash table if full, need to rehash all element */
int resize(void ***arrayptr, int *sizeptr){
  int newSize = *sizeptr * 2;
  int i; 
  void **newArray = malloc(newSize * sizeof(void*));
  for(i=0; i< *sizeptr; i++){
    newArray[i] = (char *)malloc(strlen((*arrayptr)[i]));
    strcpy((char *)newArray, (*arrayptr)[i]);
  }
  free(*arrayptr);
  
  *arrayptr = newArray;
  return 0;
  
}

/* delete a element in hashtable */
int delete(void *hashTable[], char *s){
  int h;
  h = hashcode(s);

  if(hashTable[h%INITIAL_TABLE_LEN] == NULL)
    {
      printf("Not being used before\n");
      return 1;
    }

  free(hashTable[h%INITIAL_TABLE_LEN]);
  hashTable[h%INITIAL_TABLE_LEN] = NULL;
  return 0;
  
}

/* clear the table */
int clear(void ***hashTable){
  printf("Clear the hash table\n");
  free(*hashTable);
  *hashTable = NULL;
  return 0;
}
