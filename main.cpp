#include <iostream>
#include <vector>

using namespace std;

vector<int> ALG1(vector<int> arr);    // INSERTION-SORT
vector<int> ALG2(vector<int> arr);     // HEAPSORT
vector<int> ALG3(vector<int> arr);     // QUICKSORT

void InsertionSort(vector<int> &arr);           // INSERTION-SORT
void Heapsort(vector<int> &arr); // HEAPSORT
void QuickSort(vector<int> &arr, int beg, int end); // QUICK-SORT

int Partition(vector<int> &arr, int beg, int end); // QUICK-SORT
void MaxHeapify(vector<int> &arr, int root, int heapSize); // HEAPSORT
void BuildMaxHeap(vector<int> &arr, int heapSize); // HEAPSORT

void PrintVector(vector<int> arr);
void SwapElementsInVector(vector<int> &arr, int index1, int index2);
int Left(int index);
int Right(int index);
int Parent(int index);

int main() {
    vector<int> arr = {19, 12, 1, 20, 100, 2, 3, 9, 4, 55, 22, 124, 234, 4325, 0, 11, 278};
    vector<int> sorted1, sorted2, sorted3;
    int startTime1, startTime2, startTime3, endTime1, endTime2, endTime3;
    PrintVector(arr);

    cout << "Insertion Sort" << endl;
    startTime1 = clock();
    sorted1 = ALG1(arr);
    endTime1 = clock();
    PrintVector(sorted1);
    cout << "Time: " + to_string(endTime1 - startTime1) << endl;

    cout << "Heap Sort" << endl;
    startTime2 = clock();
    sorted2 = ALG2(arr);
    endTime2 = clock();
    PrintVector(sorted2);
    cout << "Time: " + to_string(endTime2 - startTime2) << endl;

    cout << "Quick Sort" << endl;
    startTime3 = clock();
    sorted3 = ALG3(arr);
    endTime3 = clock();
    PrintVector(sorted3);
    cout << "Time: " + to_string(endTime3 - startTime3) << endl;

    return 0;
}

// INSERTION-SORT
vector<int> ALG1(vector<int> arr) {
    InsertionSort(arr);
    return arr;
}

// HEAPSORT
vector<int> ALG2(vector<int> arr) {
    Heapsort(arr);
    return arr;
}

// QUICKSORT
vector<int> ALG3(vector<int> arr) {
    QuickSort(arr, 0, arr.size() - 1);
    return arr;
}

void InsertionSort(vector<int> &arr) {
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

void Heapsort(vector<int> &arr) {
    int heapSize = arr.size();
    BuildMaxHeap(arr, heapSize);
    for(int i = heapSize - 1; i > 1; i--) {
        SwapElementsInVector(arr, 0, i);
        heapSize = heapSize - 1;
        MaxHeapify(arr, 0, heapSize);
    }
}

void QuickSort(vector<int> &arr, int beg, int end) {
    if(beg < end) {
        int q = Partition(arr, beg, end);
        QuickSort(arr, beg, q - 1);
        QuickSort(arr, q + 1, end);
    }
}

int Partition(vector<int> &arr, int beg, int end) {
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

void MaxHeapify(vector<int> &arr, int root, int heapSize) {
    int leftChild = Left(root);
    int rightChild = Right(root);
    int largest;

    if(leftChild < heapSize - 1 && arr[leftChild] > arr[root]) {
        largest = leftChild;
    }
    else {
        largest = root;
    }

    if(rightChild < heapSize - 1 && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    if(largest != root) {
        SwapElementsInVector(arr, root, largest);
        MaxHeapify(arr, largest, heapSize);
    }
}

void BuildMaxHeap(vector<int> &arr, int heapSize) {
    for(int i = (heapSize - 1) / 2; i >= 0; i--) {
        MaxHeapify(arr, i, heapSize);
    }
}

void PrintVector(vector<int> arr) {
    for(int & elements : arr) {
        cout << elements << " ";
    }
    cout << endl;
}

void SwapElementsInVector(vector<int> &arr, int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

int Left(int index) {
    return 2 * index;
}

int Right(int index) {
    return (2 * index) + 1;
}

int Parent(int index) {
    return index / 2;
}
