#include <stdlib.h>
#include <stdio.h>

// Implementation a linked list with insertion in the beginning

typedef struct list {
  int key;
  struct list *nxt;
} list;

list *find(list *init, int key) {
  list *aux = init;
  while(aux) {
    if(aux->key == key) return aux;
    aux = aux->nxt;
  }
  return NULL;
}

void insert(list **init, int key) {
  list *node = find(*init, key);
  if(node) return;

  list *new = (list*)malloc(sizeof(list));
  if(!new) {
    printf("error: memory alocation\n");
    return;
  }

  new->key = key;
  new->nxt = *init;
  *init = new;
}

void delete(list **init, int key) {
  list *aux = *init, *prev = NULL;
  while(aux) {
    if(aux->key == key) {
      if(!prev) {
        *init = aux->nxt;
        free(aux);
        return;
      }
      else {
        prev->nxt = aux->nxt;
        free(aux);
        return;
      }
    }
    prev = aux;
    aux = aux->nxt;
  }
}

int main() {
  list *init = NULL, *aux; // Initializing list

  insert(&init, 10); // Insert elements in the list
  insert(&init, 10);
  insert(&init, 20);
  insert(&init, 30);
  insert(&init, 40);
  insert(&init, 40);

  aux = init; // Print elements of the list
  while(aux) { 
    printf("%d ", aux->key);
    aux = aux->nxt;
  }
  printf("\n");

  if(find(init, 20)) printf("key found\n"); // Remove elements from the list
  delete(&init, 20);
  if(find(init, 20)) printf("key found\n");

  aux = init;
  while(aux) {
    printf("%d ", aux->key);
    aux = aux->nxt;
  }
  printf("\n");

  aux = init; //Free space of memory for alocation
  while(aux) {
    list *tmp = aux;
    free(tmp);
    aux = aux->nxt;
  }

  return 0;
}