"""
Task: Implementation and Time Analysis of Tower of Hanoi (Recursive)
"""
def tower_of_hanoi(n, from_peg, to_peg, aux_peg):
    if n == 0:
        return
    tower_of_hanoi(n-1, from_peg, aux_peg, to_peg)
    print(f"Move disk {n} from {from_peg} to {to_peg}")
    tower_of_hanoi(n-1, aux_peg, to_peg, from_peg)
if __name__ == "__main__":
    import time
    n = 3
    start = time.time()
    tower_of_hanoi(n, 'A', 'C', 'B')
    end = time.time()
    print(f"Time: {end-start:.6f}s")
"""
Time Complexity: O(2^n)
Space Complexity: O(n)
"""
