#include "DataGenerator.h"

void generateRandomData(string words[], int n, string randomData[], int dataSize) {
    for(int i = 0; i < dataSize; i++) {
        int randomIndex = rand() % n;
        randomData[i] = words[randomIndex];
    }
}

void generateOrderedData(string words[], int n, string orderedData[], int dataSize) {
    for(int i = 0; i < dataSize; i++) {
        orderedData[i] = words[i % n];
    }
}

void generateNearlyOrderedData(string words[], int n, string nearlyOrderedData[], int dataSize) {
    for(int i = 0; i < dataSize; i++) {
        nearlyOrderedData[i] = words[i % n];
    }
    for(int i = 0; i < dataSize / 10; i++) {
        int index1 = rand() % dataSize;
        int index2 = rand() % dataSize;
        swap(nearlyOrderedData[index1], nearlyOrderedData[index2]);
    }
}

