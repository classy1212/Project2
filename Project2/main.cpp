#include <bits/stdc++.h>
#include "AVLTree.h"
#include "BST.h"

using namespace std;
using namespace std::chrono;

void generateRandomData(string words[], int n, string randomData[], int dataSize);
void generateOrderedData(string words[], int n, string orderedData[], int dataSize);
void generateNearlyOrderedData(string words[], int n, string nearlyOrderedData[], int dataSize);
void testPerformance(string words[], int n, string data[], int dataSize);

int main() {
    srand(time(0));
     string words[] = {"Arachnophobia", "Agoraphobia", "Acrophobia", "Aerophobia", "Algophobia", "Aichmophobia", "Amaxophobia", "Androphobia", "Astraphobia", "Claustrophobia", "Cynophobia", "Dentophobia", "Entomophobia", "Gephyrophobia", "Hemophobia", "Ichthyophobia", "Katsaridaphobia", "Lilapsophobia", "Mysophobia", "Nyctophobia", "Ophidiophobia", "Pediophobia", "Quadraphobia", "Ranidaphobia", "Selachophobia", "Thalassophobia"};
    int n = sizeof(words) / sizeof(words[0]);
    int dataSize = 1000;

    string randomData[dataSize];
    generateRandomData(words, n, randomData, dataSize);
    cout << "Random Data:\n";
    for(int i = 0; i < dataSize; i++) {
        cout << randomData[i] << "\n";
    }
    cout <<endl;

    string orderedData[dataSize];
    generateOrderedData(words, n, orderedData, dataSize);
    cout << "\nOrdered Data:\n";
    for(int i = 0; i < dataSize; i++) {
        cout << orderedData[i] << "\n";
    }
    cout <<endl;

    string nearlyOrderedData[dataSize];
    generateNearlyOrderedData(words, n, nearlyOrderedData, dataSize);
    cout << "\nNearly Ordered Data:\n";
    for(int i = 0; i < dataSize; i++) {
        cout << nearlyOrderedData[i] << "\n";
    }
    cout <<endl;

    cout << "Testing performance on random data...\n";
    testPerformance(words, n, randomData, dataSize);

    cout << "Testing performance on ordered data...\n";
    testPerformance(words, n, orderedData, dataSize);

    cout << "Testing performance on nearly ordered data...\n";
    testPerformance(words, n, nearlyOrderedData, dataSize);

    return 0;
}

void generateRandomData(string words[], int n, string randomData[], int dataSize) {
    for (int i = 0; i < dataSize; i++) {
        int randomIndex = rand() % n;
        randomData[i] = words[randomIndex];
    }
}

void generateOrderedData(string words[], int n, string orderedData[], int dataSize) {
    for (int i = 0; i < dataSize; i++) {
        orderedData[i] = words[i % n];
    }
}

void generateNearlyOrderedData(string words[], int n, string nearlyOrderedData[], int dataSize) {
    for (int i = 0; i < dataSize; i++) {
        nearlyOrderedData[i] = words[i % n];
    }

    for (int i = 0; i < dataSize / 10; i++) {
        int index1 = rand() % dataSize;
        int index2 = rand() % dataSize;
        swap(nearlyOrderedData[index1], nearlyOrderedData[index2]);
    }
}

void testPerformance(string words[], int n, string data[], int dataSize) {
    AVLTree avl;
    BST bst;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < dataSize; i++) {
        avl.insert(data[i]);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by AVL to insert data: " << duration.count() << " microseconds\n";

    start = high_resolution_clock::now();
    for (int i = 0; i < dataSize; i++) {
        bst.insert(data[i]);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by BST to insert data: " << duration.count() << " microseconds\n";
}
