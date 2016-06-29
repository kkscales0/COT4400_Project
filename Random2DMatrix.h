//
// Created by Kyle Scales on 6/29/16.
//

#ifndef SCALES_COT4400_ASSIGN_RANDOM2DMATRIX_H
#define SCALES_COT4400_ASSIGN_RANDOM2DMATRIX_H

#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sys/time.h>
#include <iostream>

using namespace std;

class Random2DMatrix {
public:
    Random2DMatrix(int rows, int columns);
    Random2DMatrix(const Random2DMatrix& other);
    ~Random2DMatrix();
    void InsertionSort(vector<int> &arr);

    void Heapsort(vector<int> &arr);

    void Quicksort(vector<int> &arr, int beg, int end);

    void PrintRuntimeToFile(int ns, int nf, int d, string fileName, string sortName);

private:
    vector<vector<int>> matrix;

    void MaxHeapify(vector<int> &arr, int root, int heapSize);

    void BuildMaxHeap(vector<int> &arr, int heapSize);

    int LeftChild(int index);

    int RightChild(int index);

    int Partition(vector<int> &arr, int beg, int end);

    void SwapElementsInVector(vector<int> &arr, int index1, int index2);
};


#endif //SCALES_COT4400_ASSIGN_RANDOM2DMATRIX_H
