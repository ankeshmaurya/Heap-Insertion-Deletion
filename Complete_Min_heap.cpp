#include <iostream>
using namespace std;

// Function to heapify a subtree with root at given index
void minHeapify(int arr[], int n, int i) {
    int smallest = i;       
    int l = 2 * i + 1;      
    int r = 2 * i + 2;      
    // Check if left child is smaller than the root
    if (l < n && arr[l] < arr[smallest]) {
        smallest = l;
    }

    // Check if right child is smaller than the smallest so far
    if (r < n && arr[r] < arr[smallest]) {
        smallest = r;
    }

    // If the smallest is not the root
    if (smallest != i) {
        swap(arr[i], arr[smallest]); 
        minHeapify(arr, n, smallest); 
    }
}

// Function to build the Min Heap
void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

// Function to insert a new key into the Min Heap
void insert(int arr[], int& n, int key) {
    n++; 
    arr[n - 1] = key; 

    // Fix the Min Heap property if it is violated
    int i = n - 1;
    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to delete the root of the Min Heap
int deleteRoot(int arr[], int& n) {
    if (n <= 0) {
        cout << "Heap is empty!" << endl;
        return -1;
    }

    int root = arr[0]; 
    arr[0] = arr[n - 1]; 
    n--;
    minHeapify(arr, n, 0);

    return root;
}

// Function to print the heap
void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the heap: ";
    cin >> n;

    int arr[100]; // Array to hold the heap elements
    cout << "Enter the elements of the heap:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Build the Min Heap
    buildMinHeap(arr, n);

    cout << "Min Heap: ";
    printHeap(arr, n);

    // Insertion operation
    int key;
    cout << "Enter a value to insert: ";
    cin >> key;
    insert(arr, n, key);
    cout << "Heap after insertion: ";
    printHeap(arr, n);

    // Deletion operation
    cout << "Deleting the root element...\n";
    int deletedValue = deleteRoot(arr, n);
    if (deletedValue != -1) {
        cout << "Deleted value: " << deletedValue << endl;
    }
    cout << "Heap after deletion: ";
    printHeap(arr, n);

    return 0;
}
