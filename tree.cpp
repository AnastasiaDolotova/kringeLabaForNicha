#include "tree.h"

int size(node *root) {
    if (root == NULL)
        return 0;
    return size(root->right) + size(root->left) + 1;
}

int depth(node *root) {
    int h1 = 0, h2 = 0;
    if (root == NULL)
        return 0;
    if (root->left)
        h1 = depth(root->left);
    if (root->right)
        h2 = depth(root->right);
    if (h1 > h2)
        return (h1 + 1);
    else
        return (h2 + 1);
}

int getSum(int n) {
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

node *add(node *head, int n) {
    int s = getSum(n);
    if (head == NULL) {
        head = new node;
        head->val = n;
        head->sum = s;
        head->left = NULL;
        head->right = NULL;
    } else {
        if (s < head->sum) {
            head->left = add(head->left, n);
        } else {
            head->right = add(head->right, n);
        }
    }
    return head;
}

void preorder(const node *root) {
    std::cout << root->val << " ";
    if (root->left) preorder(root->left);
    if (root->right) preorder(root->right);
}

void inorder(const node *root) {
    if (root->left) inorder(root->left);
    std::cout << root->val << " ";
    if (root->right) inorder(root->right);
}

void postorder(const node *root) {
    if (root->left) postorder(root->left);
    if (root->right) postorder(root->right);
    std::cout << root->val << " ";
}

void print(node *p, int indent) {
    if (p) {
        std::cout << std::setw(indent) << p->val << " (" << p->sum << ")" << std::endl;
        if (p->left)
            print(p->left, indent - 4);
        if (p->right)
            print(p->right, indent + 4);
    }
}

void deleteTree(node *root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

node *min(node *root) {
    if (root->left == NULL) return root;
    return min(root->left);
}

node *deleteNode(node *root, int n) {
    if (root == NULL) return root;
    if (root->val == n) {
        if (root->left == NULL) {
            node *tmp = root->right;
            delete root;
            return tmp;
        } else if (root->right == NULL) {
            node *tmp = root->left;
            delete root;
            return tmp;
        } else {
            node *tmp = min(root->right);
            root->val = tmp->val;
            root->sum = tmp->sum;
            root->right = deleteNode(root->right, tmp->val);
        }
    } else {
        root->right = deleteNode(root->right, n);
        root->left = deleteNode(root->left, n);
    }
    return root;
}

void printTree(node *root) {
    std::cout << "Tree:" << std::endl;
    print(root);
    std::cout << "Pre-order:" << std::endl;
    preorder(root);
    std::cout << std::endl << "Post-order:" << std::endl;
    postorder(root);
    std::cout << std::endl << "In-order: " << std::endl;
    inorder(root);
    std::cout << std::endl;
}