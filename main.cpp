#include <iostream>
#include <vector>

using namespace std;

void PrintVector(vector<int> arr);

void ALG1(vector<int> &arr); // INSERTION-SORT
void ALG2(vector<int> arr); // HEAPSORT
void ALG3(vector<int> arr); // QUICKSORT

void InsertionSort(vector<int> &arr); // INSERTION-SORT

int main() {
    vector<int> arr = {19, 12, 1, 20, 100, 2, 3, 9};
    //ALG2(arr);
    PrintVector(arr);
    ALG1(arr);
    PrintVector(arr);

    return 0;
}

void PrintVector(vector<int> arr) {
    for(int & elements : arr) {
        cout << elements << " ";
    }
    cout << endl;
}

// INSERTION-SORT
void ALG1(vector<int> &arr) {
    InsertionSort(arr);
}

// HEAPSORT
void ALG2(vector<int> arr) {
    int n = arr.size();
    cout << n << endl;
    for(int & nums : arr) {
        cout << nums << " ";
    }
}

// QUICKSORT
void ALG3(vector<int> arr) {

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