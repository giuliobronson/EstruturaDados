#include <stdio.h>
#define N 6

int queue[N];
int l = N, r = N;

void insert(int *queue, int *l, int *r, int key) {
  if((*r + 1) % N == *l) return;
  if(*r == N) {
    *r = 0;
    *l = 0;
  }
  else 
    *r = (*r + 1) % N;
  queue[*r] = key;
}

void delete(int *queue, int *l, int *r) {
  if(*l == N) {
    printf("error: empty queue\n");
    return;
  }
  if(*l == *r) {
    *l = N;
    *r = N;
  }
  else 
    *l = (*l + 1) % N;
}

int main() {
  insert(queue, &l, &r, 10);
  insert(queue, &l, &r, 20);
  insert(queue, &l, &r, 30);
  insert(queue, &l, &r, 40);
  insert(queue, &l, &r, 50);

  delete(queue, &l, &r);
  delete(queue, &l, &r);

  insert(queue, &l, &r, 60);

  return 0;
}