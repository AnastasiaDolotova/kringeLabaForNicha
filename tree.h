#ifndef INC_18_TREE_H
#define INC_18_TREE_H

#include <iostream>
#include <iomanip>

struct node {
    int val;
    node *left;
    node *right;
    int sum;
};

int size(node *root);
int depth(node *root);
int getSum(int n);
node *add(node *head, int n);
void preorder(const node *root);
void inorder(const node *root);
void postorder(const node *root);
void print(node *p, int indent = 20);
void deleteTree(node *root);
node *min(node *root);
node *deleteNode(node *root, int n);
void printTree(node *root);

#endif //INC_18_TREE_H
