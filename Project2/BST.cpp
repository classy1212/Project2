
#include "BST.h"

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    deleteNode(root);
}

void BST::insert(string data) {
    if (root == nullptr) {
        root = new BSTNode(data);
    } else {
        insert(root, data);
    }
}

BST::BSTNode* BST::search(string data) {
    return searchBST(root, data);
}

void BST::insert(BSTNode* node, string data) {
    if (data < node->data) {
        if (node->left == nullptr) {
            node->left = new BSTNode(data);
        } else {
            insert(node->left, data);
        }
    } else {
        if (node->right == nullptr) {
            node->right = new BSTNode(data);
        } else {
            insert(node->right, data);
        }
    }
}

BST::BSTNode* BST::searchBST(BSTNode* node, string data) {
    if (node == nullptr || node->data == data)
        return node;
    if (node->data < data)
        return searchBST(node->right, data);
    return searchBST(node->left, data);
}

void BST::deleteNode(BSTNode* node) {
    if (node == nullptr) {
        return;
    }
    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
}

