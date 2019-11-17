#ifndef HASH_H
#define HASH_H

typedef struct hash_t{
  struct hash_node_t **bucket; 	/* array of hash node */
  int size;			/* size of the array */
  int entries;			/* number of entries in table */
  int downshift;		/* shift count, usead hash function */
  int mask;			/* used to select bits for hashing */
} hash_t;

#define HASH_FAIL -1

void hash_init(hash_t *tptr, int buckets);

int hash_lookup(const hash_t *tptr, const char *key);

int hash_insert(hash_t *tptr, const char *key, int data);

int hash_delete(hash_t *tptr, const char *key);

int hash_entries(hash_t *tptr);

void hash_destroy(hash_t *tptr);

char *hash_stats(hash_t *tptr);

#endif
