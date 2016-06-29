#include <iostream>
#include <vector>
#include "Random2DMatrix.h"

using namespace std;

void ALG1(Random2DMatrix arr);    // INSERTION-SORT
void ALG2(Random2DMatrix arr);    // HEAPSORT
void ALG3(Random2DMatrix arr);    // QUICKSORT

void PrintVector(vector<int> arr);

namespace constants {
    const int ns = 1000, nf = 20000, d = 1000, m = 10;
}

int main() {


    Random2DMatrix matrix = Random2DMatrix(constants::m, constants::nf);

    ALG1(matrix);
    ALG2(matrix);
    ALG3(matrix);

    return 0;
}

// INSERTION-SORT
void ALG1(Random2DMatrix arr) {
    arr.PrintRuntimeToFile(constants::ns, constants::nf, constants::d, "insertion-sort.txt", "Insertion Sort");
}

// HEAPSORT
void ALG2(Random2DMatrix arr) {
    arr.PrintRuntimeToFile(constants::ns, constants::nf, constants::d, "heapsort.txt", "Heapsort");
}

// QUICKSORT
void ALG3(Random2DMatrix arr) {
    arr.PrintRuntimeToFile(constants::ns, constants::nf, constants::d, "quicksort.txt", "Quicksort");
}

void PrintVector(vector<int> arr) {
    for(int & elements : arr) {
        cout << elements << " ";
    }
    cout << endl;
}
