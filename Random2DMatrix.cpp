//
// Created by Kyle Scales on 6/29/16.
//

#include "Random2DMatrix.h"

Random2DMatrix::Random2DMatrix(int rows, int columns) {
    matrix.resize(rows, vector<int> (columns));

    for(int run = 0; run < matrix.size(); run++) {
        for(int n = 0; n < matrix[run].size(); n++) {
            matrix[run][n] = rand();
        }
    }
}

Random2DMatrix::Random2DMatrix(const Random2DMatrix& other) {
    matrix.resize(other.matrix.size(), vector<int> (other.matrix[0].size()));

    for(int run = 0; run < matrix.size(); run++) {
        for(int n = 0; n < matrix[run].size(); n++) {
            matrix[run][n] = other.matrix[run][n];
        }
    }
}

Random2DMatrix::~Random2DMatrix() {
    for(int i = 0; i < matrix.size(); i++) {
        matrix[i].clear();
    }
    matrix.clear();
}

void Random2DMatrix::InsertionSort(vector<int> &arr) { // INSERTION-SORT
    int key, i;

    for(int j = 1; j <= arr.size() - 1; j++) {
        key = arr[j];
        i = j - 1;
        while(i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[ i + 1] = key;
    }
}

void Random2DMatrix::Heapsort(vector<int> &arr) {// HEAPSORT
    int heapSize = arr.size();
    BuildMaxHeap(arr, heapSize);
    for(int i = heapSize - 1; i >= 1; i--) {
        SwapElementsInVector(arr, 0, i);
        heapSize = heapSize - 1;
        MaxHeapify(arr, 0, heapSize);
    }
}

void Random2DMatrix::Quicksort(vector<int> &arr, int beg, int end) { // QUICKSORT
    if(beg < end) {
        int q = Partition(arr, beg, end);
        Quicksort(arr, beg, q - 1);
        Quicksort(arr, q + 1, end);
    }
}

void Random2DMatrix::PrintRuntimeToFile(int ns, int nf, int d, string fileName, string sortName) {
    ofstream opFile;
    opFile.open (fileName);
    opFile << "Runtimes for " + sortName << endl << endl;

    if(sortName == "Insertion Sort" || sortName == "Heapsort" || sortName == "Quicksort") {
        // Specifies the number of elements to run the algorithm with.
        for (int n = ns; n <= nf; n += d) {
            vector<long> runtimeArray;

            cout << "Please wait, running " + sortName << " with " + to_string(n) + " elements..." << endl;

            // Specifies which run the program is on.
            for (int run = 0; run < matrix.size(); run++) {
                // Creates temporary vector to run algorithms with.
                vector<int> arr(matrix[run].begin(), matrix[run].begin() + n);
                timeval startTime, endTime;

                if (sortName == "Insertion Sort") {
                    gettimeofday(&startTime, 0);
                    InsertionSort(arr);

                } else if (sortName == "Heapsort") {
                    gettimeofday(&startTime, 0);
                    Heapsort(arr);

                } else if (sortName == "Quicksort") {
                    gettimeofday(&startTime, 0);
                    Quicksort(arr, 0, arr.size() - 1);
                }

                gettimeofday(&endTime, 0);

                long microseconds =
                        (endTime.tv_sec * 1000000 + endTime.tv_usec) - (startTime.tv_sec * 1000000 + startTime.tv_usec);
                runtimeArray.push_back(microseconds);

                arr.clear();
            }

            double average = 0;
            for (int i = 0; i < runtimeArray.size(); i++) {
                average += runtimeArray[i];
            }
            average = average / runtimeArray.size();

            //TODO: SELECT FILE OR STD OUTPUT
            opFile << "Average runtime for " + to_string(n) + " elements: " + to_string(average) << endl;
            //cout << "Average runtime for " + to_string(n) + " elements: " + to_string(average) << endl;

            runtimeArray.clear();
        }
    }
    else {
        opFile << "Sort Name does not exist" << endl;
    }

    opFile.close();
}

void Random2DMatrix::MaxHeapify(vector<int> &arr, int root, int heapSize) {
    int leftChild = LeftChild(root);
    int rightChild = RightChild(root);
    int largest;

    if(leftChild <= heapSize - 1 && arr[leftChild] > arr[root]) {
        largest = leftChild;
    }
    else {
        largest = root;
    }

    if(rightChild <= heapSize - 1 && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    if(largest != root) {
        SwapElementsInVector(arr, root, largest);
        MaxHeapify(arr, largest, heapSize);
    }
}

void Random2DMatrix::BuildMaxHeap(vector<int> &arr, int heapSize) {
    for(int i = (heapSize - 1) / 2; i >= 0; i--) {
        MaxHeapify(arr, i, heapSize);
    }
}

int Random2DMatrix::LeftChild(int index) {
    return 2 * index;
}

int Random2DMatrix::RightChild(int index) {
    return (2 * index) + 1;
}

int Random2DMatrix::Partition(vector<int> &arr, int beg, int end) {
    int q = arr[end];
    int i = beg - 1;
    for(int j = beg; j < end; j++) {
        if(arr[j] <= q) {
            i = i + 1;
            SwapElementsInVector(arr, i, j);
        }
    }
    SwapElementsInVector(arr, i + 1, end);
    return i + 1;
}

void Random2DMatrix::SwapElementsInVector(vector<int> &arr, int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

