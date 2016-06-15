#include <iostream>
#include <vector>

using namespace std;

void ALG1(vector<int> a); // INSERTION-SORT
void ALG2(vector<int> a); // HEAPSORT
void ALG3(vector<int> a); // QUICKSORT

int main() {
    cout << "Hello, World!" << endl;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    ALG1(arr);
    return 0;
}

// INSERTION-SORT
void ALG1(vector<int> a) {
    int n = a.size();
    cout << n << endl;
    for(int & nums : a) {
        cout << nums << " ";
    }
}

// HEAPSORT
void ALG2(vector<int> a) {

}

// QUICKSORT
void ALG3(vector<int> a) {

}