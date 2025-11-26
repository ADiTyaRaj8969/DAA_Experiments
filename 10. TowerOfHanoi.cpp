/*
Task: Implementation and Time Analysis of Tower of Hanoi (Recursive)
*/
#include <iostream>
#include <ctime>
using namespace std;

void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 0)
        return;
    towerOfHanoi(n - 1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    towerOfHanoi(n - 1, aux, to, from);
}
int main()
{
    int n = 3;
    clock_t start = clock();
    towerOfHanoi(n, 'A', 'C', 'B');
    clock_t end = clock();
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}
/*
Time Complexity: O(2^n)
Space Complexity: O(n)
*/
