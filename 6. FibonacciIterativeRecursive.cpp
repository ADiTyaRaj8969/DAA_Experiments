/*
Task: Implementation and Time Analysis of Fibonacci Program using Iterative and Recursive Method
*/
#include <iostream>
#include <ctime>
using namespace std;

long long fibonacciIterative(int n)
{
    if (n <= 1)
        return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
long long fibonacciRecursive(int n)
{
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}
int main()
{
    int n = 30;
    clock_t start = clock();
    long long res = fibonacciIterative(n);
    clock_t end = clock();
    cout << "Iterative: " << res << ", Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    start = clock();
    res = fibonacciRecursive(n);
    end = clock();
    cout << "Recursive: " << res << ", Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}
/*
Time Complexity: Iterative O(n), Recursive O(2^n)
Space Complexity: Iterative O(1), Recursive O(n)
*/
