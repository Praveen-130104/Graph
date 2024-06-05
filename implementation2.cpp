//implemenation using list

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n , m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i = 0;i<m;i++){
        int u , v;
        cin>>u>>v;
        //store in pairs if it is weighted graph 
        adj[u].push_back(v);
        //undirected graph 
        adj[v].push_back(u);
    }
    //Space complexity 
    // for directed graph - O(E)
}