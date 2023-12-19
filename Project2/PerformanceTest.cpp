#include "PerformanceTest.h"
#include "AVLTree.h"
#include "BST.h"
#include<chrono>
#include<iostream>
using namespace std;
using namespace std::chrono;

void testPerformance(string words[], int n, string data[], int dataSize) {
    AVLNode* avl = NULL;
    BST bst;
    auto start = high_resolution_clock::now();
    for(int i = 0; i < dataSize; i++) {
        avl = insert(avl, data[i]);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by AVL to insert data: " << duration.count() << " microseconds\n";

    start = high_resolution_clock::now();
    for(int i = 0; i < dataSize; i++) {
        bst.insert(data[i]);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by BST to insert data: " << duration.count() << " microseconds\n";
}

