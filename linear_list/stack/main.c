#include <stdio.h>
#define N 6

int memory[N];
int topA = -1; // Pilha vazia
int topB = N; // Pilha vazia

void pushA(int *m, int x) {
  if(topA + 1 == topB) { // Pilha cheia
    printf("Memória cheia!\n");
  }
  else {
    topA++;
    m[topA] = x;
  }
}

void pushB(int *m, int x) {
  if(topA + 1 == topB) { // Pilha cheia
    printf("Memória cheia!\n");
  }
  else {
    topB--;
    m[topB] = x;
  }
}

int popA(int *m) {
  int aux;
  if(topA == -1) {
    printf("Pilha vazia!\n");
    return -1;
  }
  else {
    aux = m[topA];
    topA--;
    return aux;
  }
}

int popB(int *m) {
  int aux;
  if(topB == N) {
    printf("Pilha vazia!\n");
    return -1;
  }
  else {
    aux = m[topB];
    topB++;
    return aux;
  }
}

int main() {
  pushA(memory, 10);
  pushA(memory, 20);
  pushB(memory, 5);
  pushB(memory, 15);
  pushA(memory, 8);
  pushB(memory, 4);
  pushA(memory, 7);

  popA(memory);
  popB(memory);
  
  return 0;
}