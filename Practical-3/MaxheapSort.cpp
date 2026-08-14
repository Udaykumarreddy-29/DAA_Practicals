#include <iostream>

using namespace std;

// Function to maintain the Max Heap property for a subtree rooted at index i
void maxHeapify(int arr[], int heapSize, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // Check if left child is larger than root
    if (left < heapSize && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check if right child is larger than current largest
    if (right < heapSize && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not the root, swap and recursively heapify the affected subtree
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, heapSize, largest);
    }
}

// Main function to perform Heap Sort
void heapSort(int arr[], int n) {
    // Step 1: Build a Max Heap from the input array
    // Start from the last non-leaf node and move upwards to the root
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }

    // Step 2: Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root (maximum element) to the end of the array
        swap(arr[0], arr[i]);

        // Call maxHeapify on the reduced heap to restore order
        maxHeapify(arr, i, 0);
    }
}

// Helper function to print the array elements
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int data[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(data) / sizeof(data[0]); // Dynamically calculate array size
    
    cout << "Original array: ";
    printArray(data, n);

    heapSort(data, n);

    cout << "Sorted array (Ascending): ";
    printArray(data, n);

    return 0;
}
