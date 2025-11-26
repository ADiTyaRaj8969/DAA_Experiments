"""
Task: Implementation and Time Analysis of Sorting Algorithms
Includes: Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort
Prints time taken for each algorithm.
"""
import time, random

def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

def selection_sort(arr):
    n = len(arr)
    for i in range(n-1):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i-1
        while j >= 0 and arr[j] > key:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key

def merge_sort(arr):
    if len(arr) > 1:
        m = len(arr)//2
        L, R = arr[:m], arr[m:]
        merge_sort(L)
        merge_sort(R)
        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]; i += 1
            else:
                arr[k] = R[j]; j += 1
            k += 1
        while i < len(L): arr[k] = L[i]; i += 1; k += 1
        while j < len(R): arr[k] = R[j]; j += 1; k += 1

def quick_sort(arr):
    def _qs(a, l, r):
        if l < r:
            pi = partition(a, l, r)
            _qs(a, l, pi-1)
            _qs(a, pi+1, r)
    def partition(a, l, r):
        pivot = a[r]
        i = l-1
        for j in range(l, r):
            if a[j] < pivot:
                i += 1
                a[i], a[j] = a[j], a[i]
        a[i+1], a[r] = a[r], a[i+1]
        return i+1
    _qs(arr, 0, len(arr)-1)

def time_sort(sort_func, arr, name):
    arr2 = arr[:]
    start = time.time()
    sort_func(arr2)
    end = time.time()
    print(f"{name} Time: {end-start:.6f}s")

if __name__ == "__main__":
    arr = [random.randint(0, 100000) for _ in range(1000)]
    time_sort(bubble_sort, arr, "Bubble Sort")
    time_sort(selection_sort, arr, "Selection Sort")
    time_sort(insertion_sort, arr, "Insertion Sort")
    arr2 = arr[:]
    start = time.time()
    merge_sort(arr2)
    end = time.time()
    print(f"Merge Sort Time: {end-start:.6f}s")
    arr2 = arr[:]
    start = time.time()
    quick_sort(arr2)
    end = time.time()
    print(f"Quick Sort Time: {end-start:.6f}s")
"""
Time Complexity:
Bubble/Selection/Insertion: O(n^2)
Merge/Quick: O(n log n)
Space Complexity:
Bubble/Selection/Insertion: O(1)
Merge: O(n)
Quick: O(log n)
"""
