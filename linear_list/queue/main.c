#include <stdio.h>
#define N 6

int queue[N];
int i = N;
int f = N;

void insert(int* queue, int *f, int *i, int x) {
  if((*f + 1) % N == *i) { 
    printf("Fila cheia!\n");
  }
  else if(*i == N) {
    *i = 0;
    *f = 0;
  }
  else
    *f = (*f + 1) % N;
  queue[*f] = x;
}

int delete(int *queue, int *i, int *f) {
  int aux = 0;

  if(*i == N) {
    printf("Fila vazia!\n");
    return -1;
  }
  else if(*i == *f) {
    aux = queue[*i];
    *i = N;
    *f = N;
    return aux;
  }
  else {
    aux = queue[*i];
    *i = (*i + 1) % N;
    return aux;
  }
}

int main() {
  insert(queue, &i, &f, 10);
  insert(queue, &i, &f, 20);
  insert(queue, &i, &f, 30);
  insert(queue, &i, &f, 40);
  insert(queue, &i, &f, 50);

  delete(queue, &i, &f);
  delete(queue, &i, &f);

  insert(queue, &i, &f, 60);

  return 0;
}