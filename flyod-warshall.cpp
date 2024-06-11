/*
    Flyod- Warshall Algorithm 
    - finds shortest path from all nodes to every other nodes
    - works for both directed and undirected graphs
    

*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<vector<int>> floydWarshall(vector<vector<int>> adj, int n) {
    vector<vector<int>> dist = adj;

   
    //setting the initial values
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
		}
	}

    // Floyd-Warshall algorithm
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
	    	for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
			}
		}
	}

    //no path -> -1
    //also if i -> i  contains neg values then it means the graph has neg cycle
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] == 1e9) {
				dist[i][j] = -1;
			}
		}
	}
	return dist;

    /*
        Time Complexity - O(V^3) - V is the number of vertices
        Space Complexity - O(V^2) 
    */
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>(n, 1e9));

    for (int i = 0; i < n; i++) {
        adj[i][i] = 0; // Distance to itself is 0
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }

    vector<vector<int>> distance = floydWarshall(adj, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                cout << distance[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
    Test case :
        5 7
        0 1 6
        0 2 2
        0 3 4
        2 4 1
        2 1 3
        3 1 1
        4 1 1

    Output :
         0  4  2  4  3
        -1  0 -1 -1 -1
        -1  2  0 -1  1
        -1  1 -1  0 -1 
        -1  1 -1 -1  0
*/