"""
Task: Implementation and Time Analysis of Fibonacci Program using Iterative and Recursive Method
"""
import time
def fibonacci_iterative(n):
    if n <= 1:
        return n
    a, b = 0, 1
    for _ in range(2, n+1):
        a, b = b, a+b
    return b
def fibonacci_recursive(n):
    if n <= 1:
        return n
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2)
if __name__ == "__main__":
    n = 30
    start = time.time()
    res = fibonacci_iterative(n)
    end = time.time()
    print(f"Iterative: {res}, Time: {end-start:.6f}s")
    start = time.time()
    res = fibonacci_recursive(n)
    end = time.time()
    print(f"Recursive: {res}, Time: {end-start:.6f}s")
"""
Time Complexity: Iterative O(n), Recursive O(2^n)
Space Complexity: Iterative O(1), Recursive O(n)
"""
