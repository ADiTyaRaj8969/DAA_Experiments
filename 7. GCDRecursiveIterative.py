"""
Task: Implementation and Time Analysis of GCD (Greatest Common Divisor) using Iterative and Recursive Method
"""
import time
def gcd_iterative(a, b):
    while b != 0:
        a, b = b, a % b
    return a
def gcd_recursive(a, b):
    if b == 0:
        return a
    return gcd_recursive(b, a % b)
if __name__ == "__main__":
    a, b = 252, 105
    start = time.time()
    res = gcd_iterative(a, b)
    end = time.time()
    print(f"Iterative: {res}, Time: {end-start:.6f}s")
    start = time.time()
    res = gcd_recursive(a, b)
    end = time.time()
    print(f"Recursive: {res}, Time: {end-start:.6f}s")
"""
Time Complexity: O(log(min(a, b)))
Space Complexity: Iterative O(1), Recursive O(log(min(a, b)))
"""
