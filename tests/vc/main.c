#include <stdlib.h>
#include <stdio.h>

typedef struct list {
  int key;
  struct list *nxt;
} list;

void insert(list **init, int key) {
  list *new = (list*)malloc(sizeof(list));

  new->key = key;
  new->nxt = *init;
  *init = new;
}

list *reverse(list **init) {
  list *init_reverse = NULL, *aux = *init;

  while(aux) {
    insert(&init_reverse, aux->key);
    list *tmp = aux;
    aux = aux->nxt;
    *init = aux;
    free(tmp);
  }

  return init_reverse;
}

int main() {
  list *init = NULL, *aux; // Initializing list

  insert(&init, 30);
  insert(&init, 20);
  insert(&init, 10);

  aux = init;
  while(aux) { // Print the elements of the list
    printf("%d ", aux->key);
    aux = aux->nxt;
  }
  printf("\n");

  list *init_reverse = reverse(&init); // Initialize reverse list

  aux = init_reverse; // Print the elements of reverse list
  while(aux) {
    printf("%d ", aux->key);
    aux = aux->nxt;
  }
  printf("\n");

  aux = init; // Print empty list
  while(aux) {
    printf("%d ", aux->key);
    aux = aux->nxt;
  }
  printf("\n");

  return 0;
}