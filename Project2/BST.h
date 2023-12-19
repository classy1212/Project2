#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

class BST {
public:
    struct BSTNode {
        string data;
        BSTNode* left;
        BSTNode* right;
        BSTNode(string data) : data(data), left(nullptr), right(nullptr) {}
    };

    BST();
    ~BST();

    void insert(string data);
    BSTNode* search(string data);

private:
    BSTNode* root;
    void insert(BSTNode* node, string data);
    void deleteNode(BSTNode* node);
    BSTNode* searchBST(BSTNode* node, string data);
};

#endif

