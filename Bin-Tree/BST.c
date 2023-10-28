#include <fenv.h>
#include <stdarg.h>
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
int tree_height(node *root, int count, int height);
node *delete(node *root, int val);
void main() {
  tree tree1;
  tree1.root = NULL;
  int a[] = {4, 3, 12, 5, 6, 9, 8, 7};
  for (int i = 0; i < 8; i++) {
    tree1.root = add_node(tree1.root, a[i]);
  }
  printf("in order:");
  display_in_order(tree1.root);
  printf("\npre order:");
  display_pre_order(tree1.root);
  printf("\npost order:");
  display_post_order(tree1.root);
  printf("\nheight:%d\n", tree_height(tree1.root, 0, 0));
  tree1.root = delete (tree1.root, 5);
  printf("display ino after del:");
  display_in_order(tree1.root);
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

int tree_height(node *root, int count, int height) {
  if (root == NULL || (root->left == NULL && root->right == NULL)) {
    if (count > height) {
      height = count;
    }
    return height;
  } else {
    if (root->left != NULL) {
      height = tree_height(root->left, count + 1, height);
    }
    height = tree_height(root->right, count + 1, height);
    return height;
  }
}
node *delete(node *root, int val) {
  if (root == NULL) {
    return NULL;
  } else if (val < root->data) {
    root->left = delete (root->left, val);
    return root;
  } else if (root->data < val) {
    root->right = delete (root->right, val);
    return root;
  } else if (root->data == val) {
    node *temp = NULL;
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    } else if (root->left != NULL && root->right == NULL) {
      temp = root->left;
      free(root);
      return temp;
    } else if (root->right != NULL && root->left == NULL) {
      temp = root->right;
      free(root);
      return temp;
    } else if (root->right != NULL && root->left != NULL) {
      node *parent = root, *child = root->right;
      while (child->left != NULL) {
        parent = child;
        child = child->left;
      }
      root->data = child->data;
      parent->left = child->right;
      free(child);
      return root;
    }
  }
}
