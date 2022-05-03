#include <stdlib.h>
#include <stdio.h>

// From postoder and simmetric routes obtain the original topology of the tree and generate 
// its preorder route

typedef struct node {
  int key;
  struct node *l;
  struct node *r;
} node;

int pos[8] = {10, 30, 20, 60, 80, 70, 50, 40};
int sim[8] = {10, 20, 30, 40, 50, 60, 70, 80};
// int pre[8] = {40, 20, 10, 30, 50, 60, 70, 80};


node *recover(int *pos, int bp, int ep, int *sim, int bs, int es) {
  node *new = (node*)malloc(sizeof(node));
  if(bp == ep) { 
    new->key = pos[bp];
    new->l = NULL;
    new->r = NULL;
  }
  else {
    int i; for(i = bs; sim[i] != pos[ep]; i++);
    int nl = i - bs;
    int nr = es - i;
    new->key = pos[ep];

    if(i == bs) new->l = NULL;
    else new->l = recover(pos, bp, ep - nr - 1, sim, bs, i - 1);
    if(i == es) new->r = NULL;
    else new->r = recover(pos, ep - nr, ep - 1, sim, i + 1, es);
  }
  return new;
}

void preorder(node *root) {
  if(root) { // Accessing the node
    printf("%d ", root->key); // Visiting the node
    preorder(root->l);
    preorder(root->r);
  }
}

int main() {
  node *root = recover(pos, 0, 7, sim, 0, 7);
  preorder(root); printf("\n");

  return 0;
}