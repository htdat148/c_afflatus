#include <stdio.h>
#include "hash.h"


int main(){
  
  /* initialize a hastable */
  hash_t hash_table;
  int value;

  hash_init(&hash_table, 32);
  hash_insert(&hash_table, "Jack", 982312);
  hash_insert(&hash_table, "Philips", 9341);
  hash_insert(&hash_table, "Sam", 123);
  hash_insert(&hash_table, "Munich", 13134);


  value = hash_lookup(&hash_table, "Jack");
  printf("\n Jack - Valua: %d", value);

  value = hash_lookup(&hash_table, "Philips");
  printf("\n Philips - Valua: %d", value);

  value = hash_lookup(&hash_table, "Sam");
  printf("\n Sam - Valua: %d", value);

  value = hash_lookup(&hash_table, "Munich");
  printf("\n Munich - Valua: %d\n", value);
}
