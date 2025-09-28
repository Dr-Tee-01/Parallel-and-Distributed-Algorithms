#include <iostream>
#include <cmath>

using namespace std;

void upSweep(int* A, int n) {
    for (int i = 0; i < log2(n); i++) {
        for (int j = 0; j < n; j += pow(2, i + 1)) {
            A[j] = A[j] + A[j - static_cast<int>(pow(2, i))];
        }
    }
}

void downSweep(int* A, int n) {
    A[n - 1] = 0;
    for (int i = log2(n) - 1; i >= 0; i--) {
        for (int j = 0; j < n; j += pow(2, i + 1)) {
            int temp = A[j];
            A[j] = A[j] + A[j - static_cast<int>(pow(2, i))];
            A[j - static_cast<int>(pow(2, i))] = temp;
        }
    }
}

int main() {
    int n;

    cout << "Enter the number of elements of the array: ";
    cin >> n;

    // Dynamic memory allocation for the array
    int* A = new int[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Up-Sweep
    upSweep(A, n);

    // Down-Sweep
    downSweep(A, n);

    // Print the result
    cout << "Prefix sum array: [";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << "]" << endl;

    // Deallocate the dynamically allocated memory
    delete[] A;

    return 0;
}
