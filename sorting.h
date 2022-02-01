//
// Created by riccardo on 03/01/22.
//

#ifndef PROGETTOTNV_SORTING_H
#define PROGETTOTNV_SORTING_H

#include "utilities.h"
#include "projectdynamic.h"


void heapSort (int aSize, RecordSoggetto aRecord[]);
void heapify(int aSize, RecordSoggetto aRecord[]);
void siftDown(int start, int end, RecordSoggetto aRecord[]);
int parent(int i);
int leftChild(int i);

#endif //PROGETTOTNV_SORTING_H
