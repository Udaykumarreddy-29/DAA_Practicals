#include <iostream>
using namespace std;

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    // Loop through every element sequentially
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return index if match is found
        }
    }
    return -1; // Return -1 if target is not in array
}

int main() {
    int arr[] = {12, 34, 55, 23, 7, 89, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    // Call the search function
    int result = linearSearch(arr, size, target);

    // Print the outcome
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}

