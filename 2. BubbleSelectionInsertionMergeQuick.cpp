/*
Task: Bubble sort, Selection sort, Insertion sort, Merge sort and Quicksort
Implements all five sorting algorithms.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
void selectionSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}
void insertionSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}
void merge(vector<int>& arr, int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void mergeSort(vector<int>& arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int partition(vector<int>& arr, int l, int r)
{
    int pivot = arr[r], i = l - 1;
    for (int j = l; j < r; ++j)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[r]);
    return i + 1;
}
void quickSort(vector<int>& arr, int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}
void printArr(const vector<int>& arr, const string& name)
{
    cout << name << ": ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}
int main()
{
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    vector<int> a1 = arr, a2 = arr, a3 = arr, a4 = arr, a5 = arr;
    bubbleSort(a1);
    printArr(a1, "Bubble");
    selectionSort(a2);
    printArr(a2, "Selection");
    insertionSort(a3);
    printArr(a3, "Insertion");
    mergeSort(a4, 0, a4.size() - 1);
    printArr(a4, "Merge");
    quickSort(a5, 0, a5.size() - 1);
    printArr(a5, "Quick");
    return 0;
}
/*
All sorts: O(n^2) except Merge/Quick: O(n log n)
*/
