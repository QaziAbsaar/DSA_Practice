#include <iostream>
using namespace std;

// Function for recursive binary search
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;  // Calculate mid-point
        
        // Check if the target is at mid
        if (arr[mid] == target) {
            return mid;  // Return the index where target is found
        }
        
        // If target is greater, search the right half
        if (arr[mid] < target) {
            return binarySearchRecursive(arr, mid + 1, right, target);
        }
        
        // If target is smaller, search the left half
        return binarySearchRecursive(arr, left, mid - 1, target);
    }
    
    return -1;  // Return -1 if the target is not found
}

int main() {
    int arr[] = {1, 2, 4, 7, 9, 12, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;
    
    int result = binarySearchRecursive(arr, 0, n - 1, target);
    
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array" << endl;

    return 0;
}
