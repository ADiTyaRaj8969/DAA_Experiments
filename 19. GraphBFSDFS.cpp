/*
Task: Implementation and Time Analysis of BFS and DFS Traversal of a Graph
*/
#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
using namespace std;

void BFS(const vector<vector<int>>& adj, int start)
{
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
void DFSUtil(const vector<vector<int>>& adj, int u, vector<bool>& visited)
{
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u])
    {
        if (!visited[v])
            DFSUtil(adj, v, visited);
    }
}
void DFS(const vector<vector<int>>& adj, int start)
{
    int n = adj.size();
    vector<bool> visited(n, false);
    DFSUtil(adj, start, visited);
}
int main()
{
    int n = 5;
    vector<vector<int>> adj = {{1, 2}, {0, 3, 4}, {0, 4}, {1}, {1, 2}};
    clock_t start = clock();
    cout << "BFS: ";
    BFS(adj, 0);
    clock_t end = clock();
    cout << "\nTime: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    start = clock();
    cout << "DFS: ";
    DFS(adj, 0);
    end = clock();
    cout << "\nTime: " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}
/*
Time Complexity: O(V+E)
Space Complexity: O(V)
*/
