"""
Task: Implementation and Time Analysis of KMP (Knuth-Morris-Pratt) String Matching Algorithm
"""
def compute_lps(pat):
    m = len(pat)
    lps = [0]*m
    length = 0
    i = 1
    while i < m:
        if pat[i] == pat[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length-1]
            else:
                lps[i] = 0
                i += 1
    return lps
def kmp_search(txt, pat):
    n, m = len(txt), len(pat)
    lps = compute_lps(pat)
    i = j = 0
    while i < n:
        if pat[j] == txt[i]:
            i += 1
            j += 1
        if j == m:
            print(f"Pattern found at index {i-j}")
            j = lps[j-1]
        elif i < n and pat[j] != txt[i]:
            if j != 0:
                j = lps[j-1]
            else:
                i += 1
if __name__ == "__main__":
    import time
    txt = "AABAACAADAABAABA"
    pat = "AABA"
    start = time.time()
    kmp_search(txt, pat)
    end = time.time()
    print(f"Time: {end-start:.6f}s")
"""
Time Complexity: O(n+m)
Space Complexity: O(m)
"""
