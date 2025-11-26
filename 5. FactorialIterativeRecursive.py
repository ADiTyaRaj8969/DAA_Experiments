"""
Task: Implementation and Time Analysis of Factorial Program using Iterative and Recursive Method
"""
import time
def factorial_iterative(n):
    res = 1
    for i in range(2, n+1):
        res *= i
    return res
def factorial_recursive(n):
    if n <= 1:
        return 1
    return n * factorial_recursive(n-1)
if __name__ == "__main__":
    n = 20
    start = time.time()
    res = factorial_iterative(n)
    end = time.time()
    print(f"Iterative: {res}, Time: {end-start:.6f}s")
    start = time.time()
    res = factorial_recursive(n)
    end = time.time()
    print(f"Recursive: {res}, Time: {end-start:.6f}s")
"""
Time Complexity: O(n)
Space Complexity: Iterative O(1), Recursive O(n)
"""
