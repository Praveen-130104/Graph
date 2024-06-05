//DFS - Dept First Search 

#include<iostream>
#include<vector>
using namespace std;

void dfs(int node , vector<int> adj[] , vector<int>& traversal , vector<bool>& visited) {
    visited[node] = true;
    traversal.push_back(node);
    for(auto neigbhours : adj[node]){
        if(!visited[neigbhours])
        dfs(neigbhours , adj , traversal , visited);
    }

    //Space Complexity - O(N +N + N) ~ O(N)
    //time Complexity - O(N) + O(2*E) for undirected graph
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

    vector<int> traversal ;
    vector<bool> visited(n+1, false);

    dfs(1 , adj , traversal , visited);

    for (int node : traversal) {
        cout << node << " ";
    }

    return 0;
}