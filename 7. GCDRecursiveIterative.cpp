/*
Task: Implementation and Time Analysis of GCD (Greatest Common Divisor) using Iterative and
Recursive Method
*/
#include <iostream>
#include <ctime>
using namespace std;

int gcdIterative(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int gcdRecursive(int a, int b)
{
    if (b == 0)
        return a;
    return gcdRecursive(b, a % b);
}
int main()
{
    int a = 252, b = 105;
    clock_t start = clock();
    int res = gcdIterative(a, b);
    clock_t end = clock();
    cout << "Iterative: " << res << ", Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    start = clock();
    res = gcdRecursive(a, b);
    end = clock();
    cout << "Recursive: " << res << ", Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}
/*
Time Complexity: O(log(min(a, b)))
Space Complexity: Iterative O(1), Recursive O(log(min(a, b)))
*/
