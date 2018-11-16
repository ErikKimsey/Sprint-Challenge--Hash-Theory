#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

typedef struct Answer {
  int index_1;
  int index_2;
} Answer;

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(length);
  Answer answ_finalle;
  printf("cap >>>> %d", ht->capacity);
  for(int i=0; i< ht->capacity; i++){
    hash_table_insert(ht, i, weights[i]);
  }
  for (int i=0; i < ht->capacity; i++){
    for (int j=i+1; j < ht->capacity; j++){
      if(ht->storage[i]->value + ht->storage[j]->value == limit){
        answ_finalle = {.index_1 = ht->storage[i]->key, .index_2 = ht->storage[j]->key};
      }
    }
  }

  return answ_finalle;
}

// int check_for_sum(int x, int y, int limit){
//   if(x + y == limit){

//   }
// }

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}