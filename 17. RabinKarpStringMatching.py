"""
Task: Implementation and Time Analysis of Rabin-Karp String Matching Algorithm
"""
def rabin_karp(txt, pat):
    d = 256
    q = 101
    n, m = len(txt), len(pat)
    h = 1
    for _ in range(m-1):
        h = (h*d)%q
    p = t = 0
    for i in range(m):
        p = (d*p + ord(pat[i]))%q
        t = (d*t + ord(txt[i]))%q
    for i in range(n-m+1):
        if p == t:
            if txt[i:i+m] == pat:
                print(f"Pattern found at index {i}")
        if i < n-m:
            t = (d*(t - ord(txt[i])*h) + ord(txt[i+m]))%q
            if t < 0:
                t += q
if __name__ == "__main__":
    import time
    txt = "AABAACAADAABAABA"
    pat = "AABA"
    start = time.time()
    rabin_karp(txt, pat)
    end = time.time()
    print(f"Time: {end-start:.6f}s")
"""
Time Complexity: O(n+m) average, O((n-m+1)m) worst
Space Complexity: O(1)
"""
