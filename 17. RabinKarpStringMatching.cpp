/*
Task: Implementation and Time Analysis of Rabin-Karp String Matching Algorithm
*/
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#define d 256
const int q = 101;  // A prime number

void rabinKarp(const string& txt, const string& pat)
{
    int n = txt.size(), m = pat.size();
    int h = 1;
    for (int i = 0; i < m - 1; ++i) h = (h * d) % q;
    int p = 0, t = 0;
    for (int i = 0; i < m; ++i)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    for (int i = 0; i <= n - m; ++i)
    {
        if (p == t)
        {
            int j = 0;
            for (; j < m; ++j)
                if (txt[i + j] != pat[j])
                    break;
            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }
        if (i < n - m)
        {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }
}
int main()
{
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";
    clock_t start = clock();
    rabinKarp(txt, pat);
    clock_t end = clock();
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}
/*
Time Complexity: O(n+m) average, O((n-m+1)m) worst
Space Complexity: O(1)
*/
