#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    // One by one move the boundary of the unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted array
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // Update minIndex if the current element is smaller
            }
        }

        // Swap the found minimum element with the first element of the unsorted subarray
        swap(arr[i], arr[minIndex]);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
