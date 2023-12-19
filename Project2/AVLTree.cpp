#include "AVLTree.h"

AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree::~AVLTree() {
    deleteNode(root);
}

void AVLTree::insert(string key) {
    root = insert(root, key);
}

AVLNode* AVLTree::search(string key) {
    return searchAVL(root, key);
}

int AVLTree::height(AVLNode* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int AVLTree::max(int a, int b) {
    return (a > b) ? a : b;
}

AVLNode* AVLTree::newNode(string key) {
    AVLNode* node = new AVLNode();
    node->key = key;
    node->height = 1;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

AVLNode* AVLTree::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

AVLNode* AVLTree::leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int AVLTree::getBalance(AVLNode* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

AVLNode* AVLTree::insert(AVLNode* node, string key) {
    if (node == nullptr)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVLNode* AVLTree::searchAVL(AVLNode* node, string key) {
    if (node == nullptr || node->key == key)
        return node;
    if (node->key < key)
        return searchAVL(node->right, key);
    return searchAVL(node->left, key);
}

void AVLTree::deleteNode(AVLNode* node) {
    if (node == nullptr)
        return;
    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
}
