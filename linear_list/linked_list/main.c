#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *nxt;
};

struct node *list = NULL;

struct node *find(int key, struct node *list, struct node **prev) {
  struct node *aux = list;
  while(aux != NULL && aux->key != key) {
    *prev = aux;
    aux = aux->nxt;
  }
  return aux;
}

int insert(int key, struct node **list) {
  struct node *new_node = NULL;
  struct node *aux;
  struct node *prev;

  aux = find(key, *list, &prev);
  
  if(aux != NULL) return -1; // Chave presente
  else {
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = key;
    new_node->nxt = NULL;
    if(prev == NULL) // Lista vazia
      *list = new_node;
    else
      prev->nxt = new_node;
    return 1;
  }
}

int delete(int key, struct node **list) {
  struct node *aux;
  struct node *prev;

  aux = find(key, *list, &prev);

  if(aux == NULL) return -1; // Não encontrado
  else if(prev == NULL) { // Remoção do primeiro elemento
    *list = aux->nxt;
    free(aux);
  }
  else {
    prev->nxt = aux->nxt;
    free(aux);
  }
}

int main() {
  list = (struct node*)malloc(sizeof(struct node));
  insert(10, &list);
  insert(20, &list);
  insert(30, &list);
  insert(40, &list);

  return 0;
}
