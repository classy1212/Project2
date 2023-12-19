#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
using namespace std;

struct AVLNode {
    string key;
    int height;
    AVLNode* left;
    AVLNode* right;
};

class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    void insert(string key);
    AVLNode* search(string key);

private:
    AVLNode* root;

    int height(AVLNode* node);
    int max(int a, int b);
    AVLNode* newNode(string key);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
    int getBalance(AVLNode* node);
    AVLNode* insert(AVLNode* node, string key);
    AVLNode* searchAVL(AVLNode* node, string key);
    void deleteNode(AVLNode* node);
};

#endif
