/*
    Bellman ford algorithm 
        -> helps to detect negative cycles(negative cycles - path weight must be reducing every time)
        -> only applicable for directed graph
    
*/

#include<iostream>
#include<vector>
using namespace std;

//0 - based indexing
vector<int> bellmanFord(vector<vector<int>> edges , int n , int m ,int start){
    vector<int> distance(n,INT_MAX);
    distance[start] = 0;

    //do relaxtion for n-1 times
    for(int i = 0;i<n-1;i++){
        //do it on all edges
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(distance[u] != INT_MAX && distance[u] + wt < distance[v]){
                distance[v] = distance[u] + wt;
            }
        }
    } 

    //to check for negative cycle
    for (auto it : edges) {
		int u = it[0];
		int v = it[1];
		int wt = it[2];
		if (distance[u] != INT_MAX && distance[u] + wt < distance[v]) {
			return { -1};
		}
	}
    return distance;
    /*
        Time Complexity: O(V*E), where V = no. of vertices and E = no. of Edges.
        Space Complexity: O(V) for the distance array which stores the minimized distances.
    */
}


int main(){
    int n , m ;
    cin>>n>>m;

    vector<vector<int>> edges( m , vector<int>(3));

    for(int i = 0;i<m;i++){
        int u , v , w;
        cin>>u>>v>>w;

        edges[i] = {u,v,w};
    }

    vector<int> distance = bellmanFord(edges , n , m , 0);

    for(auto it: distance){
        cout<<it<<" ";
    }

}
/*
    Test case :
    6 7 
    3 2 6
    5 3 1
    0 1 5
    1 5 -3
    1 2 -2
    3 4 -2
    2 4 3
*/