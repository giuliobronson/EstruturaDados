#include <stdio.h>
#define SMax 10000

int list[SMax];

int find(int *list, int key) {
  for(int i = 1; i <= list[0]; i++)
    if(list[i] == key) return i;
  return 0;
}

void insert(int *list, int key) {
  int aux = find(list, key);
  if(aux) return;

  if(list[0] == SMax - 1) {
    printf("error: full list\n");
    return;
  }
  list[++list[0]] = key;
}

void delete(int *list, int key) {
  int aux = find(list, key);
  if(aux == 0) return;

  list[0]--;
  for(int i = aux; i <= list[0]; i++)
    list[i] = list[i + 1];
}

int main() {
  insert(list, 10);
  insert(list, 8);
  insert(list, 17);
  insert(list, 15);
  insert(list, 30);
  insert(list, 5);

  printf("%d\n", find(list, 17));
  delete(list, 17);
  printf("%d\n", find(list, 17));
  return 0;
}