// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;
// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.
class Solution {
public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i) {
        bool done = false;

        while (!done) {
            int max_idx = i,
            l = 2 * i + 1,
            r = 2 * i + 2;
            if (l < n && arr[l] > arr[max_idx])
                max_idx = l;
            if (r < n && arr[r] > arr[max_idx])
                max_idx = r;
            if (max_idx != i)
                swap(arr[i], arr[max_idx]),
                i = max_idx;
            else
                done = true;
        }
    }
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n) {

        for (int i = n/2 - 1; i >= 0; --i)
            heapify(arr, n, i);
    }
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n) {

        buildHeap(arr, n);
        while (n > 1)
            swap(arr[0], arr[n - 1]),
            heapify(arr, --n, 0);
    }
};
void printArray(int arr[], int n) {

    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int arr[1000], n, T = 1;
    while(T--){
        scanf("%d",&n);
        for(int i = 0; i < n; ++i)
          scanf("%d",&arr[i]);

        Solution obj;
        obj.heapSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}
