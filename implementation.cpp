//implemenatation using adjacency matrix

#include<iostream>
using namespace std;

int main(){
    int n , m;
    cin>>n>>m;
    int adj[n+1][n+1];
    for(int i = 0;i<m;i++){
        int u , v;
        cin>>u>>v;
        adj[u][v] = 1;
        //graph is undirected , if directed remove the below line
        adj[v][u] = 1;
    }
    //space - O(N*N) - more space
}