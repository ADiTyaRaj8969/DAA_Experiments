"""
Task: Implementation and Time Analysis of Naive String Matching Algorithm
"""
def naive_search(txt, pat):
    n, m = len(txt), len(pat)
    for i in range(n-m+1):
        for j in range(m):
            if txt[i+j] != pat[j]:
                break
        else:
            print(f"Pattern found at index {i}")
if __name__ == "__main__":
    import time
    txt = "AABAACAADAABAABA"
    pat = "AABA"
    start = time.time()
    naive_search(txt, pat)
    end = time.time()
    print(f"Time: {end-start:.6f}s")
"""
Time Complexity: O((n-m+1)m)
Space Complexity: O(1)
"""
