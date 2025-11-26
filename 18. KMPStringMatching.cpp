/*
Task: Implementation and Time Analysis of KMP (Knuth-Morris-Pratt) String Matching Algorithm
*/
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

void computeLPS(const string& pat, vector<int>& lps)
{
    int m = pat.size(), len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            lps[i++] = ++len;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
}
void KMPSearch(const string& txt, const string& pat)
{
    int n = txt.size(), m = pat.size();
    vector<int> lps(m);
    computeLPS(pat, lps);
    int i = 0, j = 0;
    while (i < n)
    {
        if (pat[j] == txt[i])
        {
            ++i;
            ++j;
        }
        if (j == m)
        {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                ++i;
        }
    }
}
int main()
{
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";
    clock_t start = clock();
    KMPSearch(txt, pat);
    clock_t end = clock();
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}
/*
Time Complexity: O(n+m)
Space Complexity: O(m)
*/
