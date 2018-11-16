#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"


Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  if(length < 2){
    return NULL;
  }
  HashTable *ht = create_hash_table(length);
  Answer answ_finalle;
  for(int i=0; i< ht->capacity; i++){
    hash_table_insert(ht, i, weights[i]);
  }
  for (int i=0; i < ht->capacity; i++) {
    for (int j=i+1; j < ht->capacity; j++) {
      printf("SUM >>> %d\n", ht->storage[i]->value + ht->storage[j]->value);
      if(ht->storage[i]->value + ht->storage[j]->value == limit) {
        answ_finalle.index_2 = ht->storage[i]->key;
        answ_finalle.index_1 = ht->storage[j]->key;
      }
    }
  }
  printf("index 1 >>>> %d\n", answ_finalle.index_1);
  printf("index 2 >>>> %d\n", answ_finalle.index_2);
  return &answ_finalle;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}