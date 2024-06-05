//Finding the shortest path using dijikstra algorithm - Priority Queue

/*
    Dijkstra's Algorithm:

    Initialization:

    -> Create a distance vector of size n (number of nodes) initialized to INT_MAX. This vector keeps track of the shortest distance from the source node to each node.
    -> Set the distance of the source node (given as node.first) to 0.
    -> Create a visited vector of size n initialized to false. This vector keeps track of whether a node has been processed.
    -> Initialize a priority queue (min-heap) to store pairs of (distance, node), sorted by distance. Push the source node with distance 0 into this queue.
    
    Processing Nodes:

    While the priority queue is not empty:

        -> Extract the node vertex with the smallest distance from the queue.
        -> If vertex has already been visited, continue to the next iteration.
        -> Mark vertex as visited.
        -> For each neighbor of vertex:
        -> Calculate the tentative distance d from the source to the neighbor through vertex.
        -> If d is smaller than the currently known distance to the neighbor:
        -> Update the distance of the neighbor in the distance vector.
        -> Push the neighbor with the updated distance into the priority queue.
        
    Return:

    Return the distance vector containing the shortest distances from the source node to all other nodes.


*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//0-based indexing
vector<int> dijikstra(pair<int,int> node , vector<pair<int,int>> adj[] , int n , int m  ){

    vector<int> distance(n ,INT_MAX);
    distance[node.first] = 0;

    vector<bool> visited(n,false);

    //priority queue - min Heap
    priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> minHeap;

    minHeap.push(node);

    while(!minHeap.empty()){
        pair<int,int> vertex = minHeap.top();
        minHeap.pop();

        if(visited[vertex.first])continue;
        visited[vertex.first] = true;

        for(auto neighbour : adj[vertex.first]){
            int d = neighbour.second + distance[vertex.first] ; 
            if(d < distance[neighbour.first]){
                distance[neighbour.first] =  d;
                minHeap.push({neighbour.first , d});
            }
        }
        visited[vertex.first] = true;
    }
    return distance;

    /*
        Time Complexity - O(E * log V)
        Space Complexity - O(N + N + N) ~ O(N) without considering adj mat
    */
}

int main(){
    int n, m ;
    cin>>n>>m;

    //store the neighbour and weight in pairs
    vector<pair<int,int>> adj[n+1];
    
    for(int i = 0;i<m;i++){
        int u , v , w ;
        cin>>u>>v>>w;
        
        //undirected graph
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }
    pair<int,int> start = { 0 ,0 };

    vector<int> distance = dijikstra(start , adj , n ,m); // calculating distance from node 0

    for(auto it: distance)cout<<it<<" ";

}


/*
    Test case 1 :

    6 8 
    0 1 4
    0 2 4
    1 2 2
    2 3 3
    2 4 1
    2 5 6
    3 5 2
    4 5 3
    
    

*/

/*
    Note : 
    If the graph contains negative weight or negative cycle
    digikstra doesnot work try bellman ford algorithm

*/