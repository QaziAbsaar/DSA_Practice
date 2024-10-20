#include <iostream>
using namespace std;

// Function for linear search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // Return the index where target is found
        }
    }
    return -1;  // Return -1 if target is not found
}

int main() {
    int arr[] = {2, 4, 0, 1, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 1;
    
    int result = linearSearch(arr, n, target);
    
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array" << endl;

    return 0;
}
