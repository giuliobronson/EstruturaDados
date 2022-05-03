#include <stdlib.h>
#include <stdio.h>

// Construction of simmectric, preorder and postorder routes of a tree

typedef struct node {
  int key;
  struct node *l;
  struct node *r;
} node;

void preorder(node *root) {
  if(root) { // Accessing the node
    printf("%d ", root->key); // Visiting the node
    preorder(root->l);
    preorder(root->r);
  }
}

void simmetric(node *root) {
  if(root) { // Accessing the node
    simmetric(root->l);
    printf("%d ", root->key); // Visiting the node
    simmetric(root->r);
  }
}

void postorder(node *root) {
  if(root) { // Accessing the node
    postorder(root->l);
    postorder(root->r);
    printf("%d ", root->key); // Visiting the node
  }
}

int main() {
  node *root = (node*)malloc(sizeof(node));
  node *node1 = (node*)malloc(sizeof(node));
  node *node2 = (node*)malloc(sizeof(node));
  node *node3 = (node*)malloc(sizeof(node));
  node *node4 = (node*)malloc(sizeof(node));
  node *node5 = (node*)malloc(sizeof(node));
  node *node6 = (node*)malloc(sizeof(node));
  node *node7 = (node*)malloc(sizeof(node));

  root->key = 40;
  node1->key = 10;
  node2->key = 20;
  node3->key = 30;
  node4->key = 50;
  node5->key = 60;
  node6->key = 70;
  node7->key = 80;

  root->l = node2;
  root->r = node4;
  node2->l = node1;
  node2->r = node3;
  node1->l = NULL;
  node1->r = NULL;
  node3->l = NULL;
  node3->r = NULL;
  node4->l = node5;
  node4->r = node6;
  node5->l = NULL;
  node5->r = NULL;
  node6->l = NULL;
  node6->r = node7;
  node7->l = NULL;
  node7->r = NULL;

  preorder(root); printf("\n");
  simmetric(root); printf("\n");
  postorder(root); printf("\n");

  return 0;
}