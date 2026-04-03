#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

long long comparisons = 0;   // Global counter for performance analysis

// ─── Utility: Swap ───────────────────────────────────────────
void swap(int& a, int& b) {
    int temp = a; a = b; b = temp;
}

// ─── Utility: Print Array ────────────────────────────────────
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

// ─── Standard Lomuto Partition ───────────────────────────────
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;                        // Count every comparison
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// ─── Random Partition (Core of Randomized QuickSort) ─────────
int randomPartition(int arr[], int low, int high) {
    int randomIdx = low + rand() % (high - low + 1);  // Random pivot index
    swap(arr[randomIdx], arr[high]);                  // Move pivot to end
    return partition(arr, low, high);
}

// ─── Randomized QuickSort (Recursive) ────────────────────────
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);     // Random pivot position
        randomizedQuickSort(arr, low, pi - 1);        // Sort left
        randomizedQuickSort(arr, pi + 1, high);       // Sort right
    }
}

// ─── Performance Test Helper ──────────────────────────────────
void runTest(const string& label, int arr[], int n) {
    comparisons = 0;
    cout << "\n[ " << label << " ]\n";
    cout << "Before : "; printArray(arr, n);

    auto start = chrono::high_resolution_clock::now();
    randomizedQuickSort(arr, 0, n - 1);
    auto end   = chrono::high_resolution_clock::now();

    double ms = chrono::duration<double, milli>(end - start).count();
    cout << "After  : "; printArray(arr, n);
    cout << "Comparisons : " << comparisons << "\n";
    cout << "Time (ms)   : " << ms << "\n";
}

// ─── Main ──────────────────────────────────────────────────────
int main() {
    srand(time(0));

    // Test 1: Random Array
    int arr1[] = {9, 3, 7, 1, 5, 8, 2, 6, 4};
    runTest("Random Array", arr1, 9);

    // Test 2: Already Sorted (worst case for deterministic QSort)
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    runTest("Already Sorted", arr2, 9);

    // Test 3: Reverse Sorted
    int arr3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    runTest("Reverse Sorted", arr3, 9);

    // Test 4: All Duplicates
    int arr4[] = {5, 5, 5, 5, 5, 5, 5};
    runTest("All Duplicates", arr4, 7);

    return 0;
}