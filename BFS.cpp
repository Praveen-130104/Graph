#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(vector<int> adj[], int n) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<int> result;

    // Assuming the BFS starts from node 1 (1-based index)
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    return result;
    
    //Space Complexity - O(N+N+N) ~ O(N)
    //Time Complexity - O(N) + O(2E) (while + for (runs for degrees in each node))
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> traversal = bfs(adj, n);

    for (int node : traversal) {
        cout << node << " ";
    }

    return 0;
}
