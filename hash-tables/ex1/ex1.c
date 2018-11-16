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
    // printf("value >>>> %d\n", weights[i]);
    hash_table_insert(ht, i, weights[i]);
  }
  for (int i=0; i < ht->capacity; i++) {
    for (int j=i+1; j < ht->capacity; j++) {
      int i_val = hash_table_retrieve(ht, i);
      int j_val = hash_table_retrieve(ht, j);
      printf("SUM >>> %d, LIMIT >>> %d\n", i_val + j_val, limit);
      if(i_val + j_val == limit) {
        printf("i_1 >> %d, j_2 >> %d", i_val, j_val);
        // answ_finalle.index_2 = ht->storage[i]->key;
        // answ_finalle.index_1 = ht->storage[j]->key;
        answ_finalle.index_2 = i;
        answ_finalle.index_1 = j;
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