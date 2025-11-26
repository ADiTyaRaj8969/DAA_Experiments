"""
Task: Bubble sort, Selection sort, Insertion sort, Merge sort and Quicksort
Implements all five sorting algorithms.
"""
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
def print_arr(arr, name):
    print(f"{name}:", *arr)
if __name__ == "__main__":
    arr = [5, 2, 9, 1, 5, 6]
    a1, a2, a3, a4, a5 = arr[:], arr[:], arr[:], arr[:], arr[:]
    bubble_sort(a1); print_arr(a1, "Bubble")
    selection_sort(a2); print_arr(a2, "Selection")
    insertion_sort(a3); print_arr(a3, "Insertion")
    merge_sort(a4); print_arr(a4, "Merge")
    quick_sort(a5); print_arr(a5, "Quick")
"""
All sorts: O(n^2) except Merge/Quick: O(n log n)
"""
