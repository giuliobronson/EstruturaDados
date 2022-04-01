#include <stdlib.h>
#include <stdio.h>

// Implementation of a dequeue with dinamic allocation

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

void insert_right(list **l, list **r, int key) {
  list *aux = find(*r, key);
  if(aux) return;
  
  list *new = (list*)malloc(sizeof(list));
  if(!new) {
    printf("error: memory allocation\n");
    return;
  }

  new->key = key;
  new->next = NULL;
  new->prev = *r;

  if(!(*l && *r)) { // Empty list
    *r = new;
    *l = *r;
  }
  else {
    (*r)->next = new;
    *r = new;
  }
}

void insert_left(list **l, list **r, int key) {
  list *aux = find(*l, key);
  if(aux) return;
  
  list *new = (list*)malloc(sizeof(list));
  if(!new) {
    printf("error: memory allocation\n");
    return;
  }
  
  new->key = key;
  new->next = *l;
  new->prev = NULL;

  if(!(*l && *r)) {
    *l = new;
    *r = *l;
  }
  else {
    (*l)->prev = new;
    *l = new;
  }
}

void remove_right(list **l, list **r) {
  list *aux = *r;

  if(!aux->prev) {
    *r = NULL;
    *l = NULL;
  }
  else {
    aux->prev->next = NULL;
    *r = aux->prev;
  }
  free(aux);
}

void remove_left(list **l, list **r) {
  list *aux = *l;

  if(!aux->next) {
    *l = NULL;
    *r = NULL;
  }
  else {
    aux->next->prev = NULL;
    *l = aux->next;
  }
  free(aux);
}

int main() {
  list *l = NULL, *r = NULL;

  insert_right(&l, &r, 10);
  insert_right(&l, &r, 20);
  insert_right(&l, &r, 30);
  insert_right(&l, &r, 40);
  insert_left(&l, &r, 50);
  insert_left(&l, &r, 60);
  insert_left(&l, &r, 70);

  list *aux = l;
  while(aux) {
    printf("%d ", aux->key);
    aux = aux->next;
  }
  printf("\n");

  remove_right(&l, &r);
  remove_right(&l, &r);
  remove_left(&l, &r);

  aux = l;
  while(aux) {
    printf("%d ", aux->key);
    aux = aux->next;
  }
  printf("\n");

  return 0;
}