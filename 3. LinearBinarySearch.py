"""
Task: Implementation and Time Analysis of Linear and Binary Search Algorithm
"""
import time
def linear_search(arr, key):
    for i, v in enumerate(arr):
        if v == key:
            return i
    return -1
def binary_search(arr, key):
    l, r = 0, len(arr)-1
    while l <= r:
        m = l + (r-l)//2
        if arr[m] == key:
            return m
        if arr[m] < key:
            l = m+1
        else:
            r = m-1
    return -1
if __name__ == "__main__":
    arr = list(range(10000))
    key = 9999
    start = time.time()
    idx = linear_search(arr, key)
    end = time.time()
    print(f"Linear Search Index: {idx}, Time: {end-start:.6f}s")
    start = time.time()
    idx = binary_search(arr, key)
    end = time.time()
    print(f"Binary Search Index: {idx}, Time: {end-start:.6f}s")
"""
Linear Search: O(n)
Binary Search: O(log n)
"""
