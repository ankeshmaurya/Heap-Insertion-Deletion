#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i
void maxHeapify(int arr[], int n, int i) {
    int largest = i;         // Initialize largest as root
    int left = 2 * i + 1;    // Left child
    int right = 2 * i + 2;   // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]); // Swap root with largest
        maxHeapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}

// Function to build a Max Heap
void buildMaxHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    // Step 1: Build a Max Heap
    buildMaxHeap(arr, n);

    // Step 2: Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move the root (largest element) to the end
        swap(arr[0], arr[i]);

        // Reduce the heap size
        maxHeapify(arr, i, 0); // Call maxHeapify on the reduced heap
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
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform Heap Sort
    heapSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
