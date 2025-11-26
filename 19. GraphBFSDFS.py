"""
Task: Implementation and Time Analysis of BFS and DFS Traversal of a Graph
"""
def bfs(adj, start):
    n = len(adj)
    visited = [False]*n
    queue = [start]
    visited[start] = True
    while queue:
        u = queue.pop(0)
        print(u, end=' ')
        for v in adj[u]:
            if not visited[v]:
                visited[v] = True
                queue.append(v)
def dfs_util(adj, u, visited):
    visited[u] = True
    print(u, end=' ')
    for v in adj[u]:
        if not visited[v]:
            dfs_util(adj, v, visited)
def dfs(adj, start):
    n = len(adj)
    visited = [False]*n
    dfs_util(adj, start, visited)
if __name__ == "__main__":
    import time
    n = 5
    adj = [
        [1,2], [0,3,4], [0,4], [1], [1,2]
    ]
    start = time.time()
    print("BFS:", end=' ')
    bfs(adj, 0)
    end = time.time()
    print(f"\nTime: {end-start:.6f}s")
    start = time.time()
    print("DFS:", end=' ')
    dfs(adj, 0)
    end = time.time()
    print(f"\nTime: {end-start:.6f}s")
"""
Time Complexity: O(V+E)
Space Complexity: O(V)
"""
