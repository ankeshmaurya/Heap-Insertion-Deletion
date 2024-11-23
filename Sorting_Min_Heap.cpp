#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i
void minHeapify(int arr[], int n, int i) {
    int smallest = i;         // Initialize smallest as root
    int left = 2 * i + 1;     // Left child
    int right = 2 * i + 2;    // Right child

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    // If smallest is not the root
    if (smallest != i) {
        swap(arr[i], arr[smallest]); // Swap root with smallest
        minHeapify(arr, n, smallest); // Recursively heapify the affected sub-tree
    }
}

// Function to build a Min Heap
void buildMinHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

// Min Heap Sort function
void heapSortMinHeap(int arr[], int n) {
    // Step 1: Build a Min Heap
    buildMinHeap(arr, n);

    // Step 2: Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move the root (smallest element) to the end
        swap(arr[0], arr[i]);

        // Reduce the heap size
        minHeapify(arr, i, 0); // Call minHeapify on the reduced heap
    }

    // At the end, reverse the array to get ascending order
    for (int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n - i - 1]);
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

    // Perform Heap Sort using Min Heap
    heapSortMinHeap(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
