/*
Task: Implementation and Time Analysis of Linear and Binary Search Algorithm
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

int linearSearch(const vector<int>& arr, int key)
{
    for (int i = 0; i < arr.size(); ++i)
        if (arr[i] == key)
            return i;
    return -1;
}
int binarySearch(const vector<int>& arr, int key)
{
    int l = 0, r = arr.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == key)
            return m;
        if (arr[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int main()
{
    vector<int> arr(10000);
    for (int i = 0; i < 10000; ++i) arr[i] = i;
    int key = 9999;
    clock_t start = clock();
    int idx = linearSearch(arr, key);
    clock_t end = clock();
    cout << "Linear Search Index: " << idx << ", Time: " << (double)(end - start) / CLOCKS_PER_SEC
         << "s\n";
    start = clock();
    idx = binarySearch(arr, key);
    end = clock();
    cout << "Binary Search Index: " << idx << ", Time: " << (double)(end - start) / CLOCKS_PER_SEC
         << "s\n";
    return 0;
}
/*
Linear Search: O(n)
Binary Search: O(log n)
*/
