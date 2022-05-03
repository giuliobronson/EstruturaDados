#include <stdlib.h>
#include <stdio.h>

int pre[8] = {60, 30, 40, 50, 10, 20, 70, 80};
int sim[8] = {40, 30, 10, 50, 60, 20, 80, 70};

typedef struct tree_node {
  int key;
  struct tree_node *l;
  struct tree_node *r;
} node;

node *tree = NULL;

node *recover(int *pre, int *sim, int ip, int fp, int is, int fs) {
  node *aux = (node*)malloc(sizeof(node));
  int nl = 0, nr = 0;
  if(ip == fp) { // Árvore unitária
    aux->key = pre[ip];
    aux->l = NULL;
    aux->r = NULL;
    return aux;
  }
  else {
    aux->key = pre[ip];
    int i; for(i = is; sim[i] != pre[ip]; i++);
    if(i == is) aux->l == NULL; // Não há ramo esquerdo
    else {
      nl = i - is;
      aux->l = recover(pre, sim, ip + 1, ip + nl, is, i - 1);
    }
    if(i == fs) aux->r = NULL;
    else {
      nr = fs - i;
      aux->r = recover(pre, sim, ip + nl + 1, fp, i + 1, fs);
    }
  }
  return aux;
}

void preorder(node *r) {
  if(r != NULL) {
    printf("%d ", r->key);
    preorder(r->l);
    preorder(r->r);
  }
}

int main() {
  tree = recover(pre, sim, 0, 7, 0, 7);
  preorder(tree); printf("\n");
}