/*
Task: Implementation and Time Analysis of Sorting Algorithms
Includes: Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort
Prints time taken for each algorithm.
*/
#include <bits/stdc++.h>
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
void timeSort(void (*sortFunc)(vector<int>&), vector<int> arr, const string& name)
{
    clock_t start = clock();
    sortFunc(arr);
    clock_t end = clock();
    cout << name << " Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
}
int main()
{
    vector<int> arr(1000);
    for (int i = 0; i < 1000; ++i) arr[i] = rand();
    timeSort(bubbleSort, arr, "Bubble Sort");
    timeSort(selectionSort, arr, "Selection Sort");
    timeSort(insertionSort, arr, "Insertion Sort");
    vector<int> arr2 = arr;
    clock_t start = clock();
    mergeSort(arr2, 0, arr2.size() - 1);
    clock_t end = clock();
    cout << "Merge Sort Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    arr2 = arr;
    start = clock();
    quickSort(arr2, 0, arr2.size() - 1);
    end = clock();
    cout << "Quick Sort Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}
/*
Time Complexity:
Bubble/Selection/Insertion: O(n^2)
Merge/Quick: O(n log n)
Space Complexity:
Bubble/Selection/Insertion: O(1)
Merge: O(n)
Quick: O(log n)
*/
