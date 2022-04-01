#include <stdlib.h>
#include <stdio.h>

// Implementation a linked list with insertion in the beginning

typedef struct list {
  int key;
  struct list *next;
  struct list *prev;
} list;

list *find(list *init, int key) {
  list *aux = init;
  while(aux) {
    if(aux->key == key) return aux;
    aux = aux->next;
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
  new->next = *init;
  new->prev = NULL;

  if(!(*init)) {
    *init = new;
  }
  else {
    (*init)->prev = new;
    *init = new;
  }
}

void delete(list **init, int key) {
  list *aux = find(*init, key);

  if(!aux->prev) {
    *init = aux->next;
    if(aux->next)
      (*init)->prev = NULL;
  }
  else {
    aux->prev->next = aux->next;
    if(aux->next) 
      aux->next->prev = aux->prev;
  }
  free(aux);
}

list *merge(list **initA, list **initB) {
  list *auxA = *initA;
  list *auxB = *initB;
  list *init = NULL;

  while(auxA && auxB) {
    if(auxA->key > auxB->key) {
      insert(&init, auxA->key);
      auxA = auxA->next;
    }
    else {
      insert(&init, auxB->key);
      auxB = auxB->next;
    }
  }

  while(auxA) {
    insert(&init, auxA->key);
    auxA = auxA->next;
  }
  while(auxB) {
    insert(&init, auxB->key);
    auxB = auxB->next;
  }

  return init;
}

int main() {
  list *initA = NULL, *initB = NULL; // Initializing lists

  insert(&initA, 10); // Insert elements in the list A
  insert(&initA, 20);
  insert(&initA, 60);
  insert(&initA, 80);
  insert(&initB, 30); // Insert elements in the list B
  insert(&initB, 40);
  insert(&initB, 70);
  insert(&initB, 90);


  list *aux = initA; // Print elements of the list A
  while(aux) { 
    printf("%d ", aux->key);
    aux = aux->next;
  }
  printf("\n");

  aux = initB; // Print elements of the list B
  while(aux) { 
    printf("%d ", aux->key);
    aux = aux->next;
  }
  printf("\n");

  list *initC = merge(&initA, &initB);

  aux = initC; // Print elements of the list C
  while(aux) { 
    printf("%d ", aux->key);
    aux = aux->next;
  }
  printf("\n");

  return 0;
}