#include <stdio.h>
#define N 10000 

int find(int *ptr, int key, int TMax) {
  if(ptr[0] == 0) // Lista é vazia
    return 0; 
  int i = 1;
  while(ptr[i] != key && i <= ptr[0]) i++;
  if(i <= ptr[0]) return i;
  else return 0;
}

int insert(int *ptr, int key, int TMax) {
  int n = find(ptr, key, TMax);
  if(n == 0) {
    if(ptr[0] == TMax - 1) return 0; // Lista cheia
    ptr[0]++;
    ptr[ptr[0]] = key;
    return 1;
  }
  return 0; // Chave já está inserida
}

int delete(int *ptr, int key, int TMax) {
  if(ptr[0] == 0) return 0;
  int n = find(ptr, key, TMax);
  if(n == 0) return 0;
  int i = n;
  while(i < ptr[0]) {
    ptr[i] = ptr[i + 1];
    i++;
  }
  ptr[0]--;
  return 1;
}

int main() {
  int list[N];
  int n;

  list[0] = 0; // Lista está vazia
  insert(list, 10, N);
  insert(list, 8, N);
  insert(list, 17, N);
  insert(list, 15, N);
  insert(list, 30, N);
  insert(list, 5, N);

  printf("%d\n", find(list, 17, N));
  delete(list, 17, N);
  printf("%d\n", find(list, 17, N));

  return 0;
}