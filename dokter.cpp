#include "tree.h"

void createTree(adrNode &root) {
    root = NULL;
}

adrNode createNode(infotype x) {
    adrNode p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(adrNode &root, adrNode p) {
    if (root == NULL) {
        root = p;
    } else {
        if (p->info < root->info) {
            insertNode(root->left, p);
        } else {
            insertNode(root->right, p);
        }
    }
}

void displayTree(adrNode root) {
    if (root != NULL) {
        displayTree(root->left);
        cout << root->info << " ";
        displayTree(root->right);
    }
}

adrNode getMinNode(adrNode root) {
    adrNode p = root;
    // Loop sampai tidak bisa ke kiri lagi (nilai terkecil di BST selalu di paling kiri)
    while (p != NULL && p->left != NULL) {
        p = p->left;
    }
    return p;
}

adrNode getMaxNode(adrNode root) {
    adrNode p = root;
    // Loop sampai tidak bisa ke kanan lagi (nilai terbesar di BST selalu di paling kanan)
    while (p != NULL && p->right != NULL) {
        p = p->right;
    }
    return p;
}
