/*
Task: Implementation and Time Analysis of Factorial Program using Iterative and Recursive Method
*/
#include <iostream>
#include <ctime>
using namespace std;

long long factorialIterative(int n)
{
    long long res = 1;
    for (int i = 2; i <= n; ++i) res *= i;
    return res;
}
long long factorialRecursive(int n)
{
    if (n <= 1)
        return 1;
    return n * factorialRecursive(n - 1);
}
int main()
{
    int n = 20;
    clock_t start = clock();
    long long res = factorialIterative(n);
    clock_t end = clock();
    cout << "Iterative: " << res << ", Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    start = clock();
    res = factorialRecursive(n);
    end = clock();
    cout << "Recursive: " << res << ", Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}
/*
Time Complexity: O(n)
Space Complexity: Iterative O(1), Recursive O(n)
*/
