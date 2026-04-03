#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int parent(int i)      { return (i - 1) / 2; }
    int leftChild(int i)   { return 2 * i + 1; }
    int rightChild(int i)  { return 2 * i + 2; }

    void swapNodes(int i, int j) {
        int temp = heap[i];
        heap[i]  = heap[j];
        heap[j]  = temp;
    }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swapNodes(i, parent(i));
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int minIndex = i;
        int left     = leftChild(i);
        int right    = rightChild(i);

        if (left  < (int)heap.size() && heap[left]  < heap[minIndex]) minIndex = left;
        if (right < (int)heap.size() && heap[right] < heap[minIndex]) minIndex = right;

        if (i != minIndex) {
            swapNodes(i, minIndex);
            heapifyDown(minIndex);
        }
    }

public:
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) throw runtime_error("Heap is empty!");
        if (heap.size() == 1) {
            int val = heap[0];
            heap.pop_back();
            return val;
        }
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minVal;
    }

    int getMin() {
        if (heap.empty()) throw runtime_error("Heap is empty!");
        return heap[0];
    }

    bool isEmpty()  { return heap.empty(); }
    int  size()     { return heap.size(); }

    void display() {
        cout << "Min Heap: [ ";
        for (int val : heap) cout << val << " ";
        cout << "]" << endl;
    }
};

class MaxHeap {
private:
    vector<int> heap;

    int parent(int i)      { return (i - 1) / 2; }
    int leftChild(int i)   { return 2 * i + 1; }
    int rightChild(int i)  { return 2 * i + 2; }

    void swapNodes(int i, int j) {
        int temp = heap[i];
        heap[i]  = heap[j];
        heap[j]  = temp;
    }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swapNodes(i, parent(i));
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int maxIndex = i;
        int left     = leftChild(i);
        int right    = rightChild(i);

        if (left  < (int)heap.size() && heap[left]  > heap[maxIndex]) maxIndex = left;
        if (right < (int)heap.size() && heap[right] > heap[maxIndex]) maxIndex = right;

        if (i != maxIndex) {
            swapNodes(i, maxIndex);
            heapifyDown(maxIndex);
        }
    }

public:
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) throw runtime_error("Heap is empty!");
        if (heap.size() == 1) {
            int val = heap[0];
            heap.pop_back();
            return val;
        }
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxVal;
    }

    int getMax() {
        if (heap.empty()) throw runtime_error("Heap is empty!");
        return heap[0];
    }

    bool isEmpty()  { return heap.empty(); }
    int  size()     { return heap.size(); }

    void display() {
        cout << "Max Heap: [ ";
        for (int val : heap) cout << val << " ";
        cout << "]" << endl;
    }
};


int main() {
    int elements[] = {40, 10, 30, 5, 20, 50, 15};
    int n = sizeof(elements) / sizeof(elements[0]);

    cout << "  Inserted Elements: ";
    for (int el : elements) cout << el << " ";

    cout << "\n--- MIN HEAP (Priority Queue) ---" << endl;
    MinHeap minPQ;
    for (int i = 0; i < n; i++) minPQ.insert(elements[i]);
    minPQ.display();
    cout << "Minimum (Top):    " << minPQ.getMin()     << endl;
    cout << "Extract Min:      " << minPQ.extractMin() << endl;
    cout << "New Minimum:      " << minPQ.getMin()     << endl;
    minPQ.display();

    cout << "\n--- MAX HEAP (Priority Queue) ---" << endl;
    MaxHeap maxPQ;
    for (int i = 0; i < n; i++) maxPQ.insert(elements[i]);
    maxPQ.display();
    cout << "Maximum (Top):    " << maxPQ.getMax()     << endl;
    cout << "Extract Max:      " << maxPQ.extractMax() << endl;
    cout << "New Maximum:      " << maxPQ.getMax()     << endl;
    maxPQ.display();

    return 0;
}
