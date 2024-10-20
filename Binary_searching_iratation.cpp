#include <iostream>
using namespace std;

// Function for iterative binary search
int binarySearchIterative(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Calculate mid-point
        
        // Check if the target is at mid
        if (arr[mid] == target) {
            return mid;  // Return the index where target is found
        }
        
        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }
    
    return -1;  // Return -1 if target is not found
}

int main() {
    int arr[] = {1, 2, 4, 7, 9, 12, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 1;
    
    int result = binarySearchIterative(arr, n, target);
    
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array" << endl;

    return 0;
}
