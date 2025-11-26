/*
Task: Implementation and Time Analysis of Naive String Matching Algorithm
*/
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void naiveSearch(const string& txt, const string& pat)
{
    int n = txt.size(), m = pat.size();
    for (int i = 0; i <= n - m; ++i)
    {
        int j;
        for (j = 0; j < m; ++j)
            if (txt[i + j] != pat[j])
                break;
        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }
}
int main()
{
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";
    clock_t start = clock();
    naiveSearch(txt, pat);
    clock_t end = clock();
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}
/*
Time Complexity: O((n-m+1)m)
Space Complexity: O(1)
*/
