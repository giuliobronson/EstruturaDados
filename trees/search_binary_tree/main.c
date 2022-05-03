#include <stdlib.h>
#include <stdio.h>

int pre[8] = {40, 30, 10, 50, 60, 20, 80, 70};
int sim[8] = {10, 20, 30, 40, 50, 60, 70, 80};

typedef struct tree_node {
  int key;
  struct tree_node *l;
  struct tree_node *r;
} node;

node *tree = NULL, *father = NULL;

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

node *find(node *root, node **father, int key) {
  if(!root) return NULL;
  else if(root->key == key) return root;
  else if(key < root->key && root->l) {
    *father = root;
    return find(root->l, father, key);
  }
  else if(key > root->key && root->r) {
    *father = root;
    return find(root->r, father, key);
  }
  return root;
}

int insert(node **root, int key) {
  node *aux, *new, *father = NULL;
  aux = find(*root, &father, key);
  if(!aux) { // Árvore vazia
    new = (node*)malloc(sizeof(node));
    new->key = key;
    new->l = NULL;
    new->r = NULL;
    *root = new;
    return 1;
  }
  else if(aux->key == key) return 0;
  else {
    new = (node*)malloc(sizeof(node));
    new->key;
    new->l = NULL;
    new->r = NULL;
    if(key < aux->key) aux->l = new;
    else aux->r = new;
  }
  return 1;
}

int main() {
  tree = recover(pre, sim, 0, 7, 0, 7);
  find(tree, &father, 70);
  father = NULL;
  find(tree, &father, 75);
}