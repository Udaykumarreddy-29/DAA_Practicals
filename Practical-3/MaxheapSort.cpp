#include <iostream>

using namespace std;

void maxHeapify(int arr[], int heapSize, int i) {
    int largest = i;          
    int left = 2 * i + 1;     
    int right = 2 * i + 2;    

    if (left < heapSize && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < heapSize && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, heapSize, largest);
    }
}


void heapSort(int arr[], int n) {
    
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }


    for (int i = n - 1; i > 0; i--) {

        swap(arr[0], arr[i]);

        maxHeapify(arr, i, 0);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int data[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(data) / sizeof(data[0]); 
    
    cout << "Original array: ";
    printArray(data, n);

    heapSort(data, n);

    cout << "Sorted array (Ascending): ";
    printArray(data, n);

    return 0;
}
