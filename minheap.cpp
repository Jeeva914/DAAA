
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int main() {
    int arr[] = {3, 9, 2, 1, 4, 5};
    int n = 6;

    buildMinHeap(arr, n);

    cout << "Min Heap: ";
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
}
