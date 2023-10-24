#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *left, *right;
};
struct BST {
  struct Node *root;
};
typedef struct Node node;
typedef struct BST tree;
node *create(int data);
node *add_node(node *root, int data);
void display_in_order(node *root);
void display_pre_order(node *root);
void display_post_order(node *root);
void main() {
  tree tree1;
  tree1.root = NULL;
  int a[] = {50, 12, 35, 47, 78, 92, 14, 1, 57};
  for (int i = 0; i < 9; i++) {
    tree1.root = add_node(tree1.root, a[i]);
  }
  printf("displaing the tree:\nin order:");
  display_in_order(tree1.root);
  printf("\npre order:");
  display_pre_order(tree1.root);
  printf("\npost order:");
  display_post_order(tree1.root);
  // printf("Display End");
}
node *create(int data) {
  node *n = (node *)calloc(1, sizeof(node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}
node *add_node(node *root, int data) {
  if (root == NULL) {
    return create(data);
  } else {
    if (data < root->data) {
      root->left = add_node(root->left, data);

    } else {
      root->right = add_node(root->right, data);
    }
    return root;
  }
}
void display_pre_order(node *root) {
  if (root == NULL) {
    return;
  } else {
    printf("%d ", root->data);
    display_pre_order(root->left);
    display_pre_order(root->right);
  }
}
void display_in_order(node *root) {
  if (root == NULL) {
    return;
  } else {
    if (root->left == NULL && root->right == NULL) {
      printf("%d ", root->data);
      return;
    } else if (root->left != NULL) {
      display_in_order(root->left);
    }
    printf("%d ", root->data);
    display_in_order(root->right);
  }
}
void display_post_order(node *root) {
  if (root == NULL) {
    return;
  } else {
    if (root->left == NULL && root->right == NULL) {
      printf("%d ", root->data);
      return;

    } else if (root->left != NULL) {
      display_post_order(root->left);
    }
    display_post_order(root->right);

    printf("%d ", root->data);
  }
}
