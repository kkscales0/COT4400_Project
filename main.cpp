#include <iostream>
#include <vector>

using namespace std;

vector<int> ALG1(vector<int> arr);    // INSERTION-SORT
vector<int> ALG2(vector<int> arr);     // HEAPSORT
vector<int> ALG3(vector<int> arr);     // QUICKSORT

void InsertionSort(vector<int> &arr);           // INSERTION-SORT
void QuickSort(vector<int> &arr, int beg, int end); // QUICK-SORT

int Partition(vector<int> &arr, int beg, int end); // QUICK-SORT

void PrintVector(vector<int> arr);
void SwapElementsInVector(vector<int> &arr, int index1, int index2);

int main() {
    vector<int> arr = {19, 12, 1, 20, 100, 2, 3, 9};
    vector<int> sorted1, sorted3;
    int startTime1, startTime3, endTime1, endTime3;
    PrintVector(arr);

    cout << "Insertion Sort" << endl;
    startTime1 = clock();
    sorted1 = ALG1(arr);
    endTime1 = clock();
    PrintVector(sorted1);
    cout << "Time: " + to_string(endTime1 - startTime1) << endl;

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
vector<int> ALG2(vector<int> arr) { }

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
