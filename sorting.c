//
// Created by riccardo on 03/01/22.
//
#include "sorting.h"

/**
 * This procedure sorts an array 'aRecord'
 * @param aSize size of 'aRecord'
 * @param aRecord array to sort
 */
void heapSort (int aSize, RecordSoggetto aRecord[]){
    int end;

    heapify(aSize, aRecord);
    end = aSize - 1;
    while(end > 0) {
        swapRecord(&aRecord[end], &aRecord[0]);
        end--;
        siftDown(0, end, aRecord);
    }
}
/**
 * This procedure sets the roots in an array 'aRecord'
 * @param aSize size of 'aRecord'
 * @param aRecord array to sort
 */
void heapify(int aSize, RecordSoggetto aRecord[]){
    int start;
    start= parent(aSize);
    while(start >= 0){
        siftDown(start, aSize - 1, aRecord);
        start--;
    }
}
/**
 * This procedure sifts the an array 'aRecord'
 * @param start node to check
 * @param end last element of the array 'aRecord'
 * @param aRecord array to sift
 */
void siftDown(int start, int end, RecordSoggetto aRecord[]){
    int root;
    int child;
    int swap;

    root=start;

    /* sifts the array while it finds the last left child */
    while(leftChild(root) <= end){
        child=leftChild(root);
        swap=root;
        if(compFullName(MIN, &aRecord[swap], &aRecord[child])) // if a node is smaller than its left child...
            swap = child;                                      // ...saves the index for a swap

        if((child + 1) <= end && compFullName(MIN,                  // if a node is smaller than its right child...
                                              &aRecord[swap],       // ...saves the index for a swap
                                              &aRecord[child + 1]))
            swap = child + 1;

        if(swap == root) // if node set for a swap is the root break the iteration
            break;
        else {
            swapRecord(&aRecord[root], &aRecord[swap]); // swaps the elements of the array with root and swap index

            root=swap;
        }
    }
}
/**
 * This function finds the parent node of 'i'
 * @param i node
 * @return parent node
 */
int parent(int i){
    return floor((i - 1) / 2);
}
/**
 * This function finds the left child of 'i'
 * @param i node
 * @return left child node
 */
int leftChild(int i){
    return 2*i + 1;
}