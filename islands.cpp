/*

    Given a r*c matrix find the number of islands surrounded by water
    islands are 1's connected togethor in all directions surrounded by water

*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isExist(int r , int c , int i , int j){
    return i<r && i>=0 && j<c && j>=0;
}

void bfs(vector<vector<int>> arr , vector<vector<int>>& visited , int i , int j , int r , int c){
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j] = true;

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1},{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    while(!q.empty()){
        pair<int,int> node  = q.front();
        q.pop();
        int u = node.first;
        int v = node.second;
        
        for (auto dir : directions) {
            int row = u + dir.first;
            int col = v + dir.second;
            if (isExist(r, c, row, col) && arr[row][col] && !visited[row][col]) {
                q.push({row, col});
                visited[row][col] = true;
            }
        }
    }
    /*
        Time Complexity -  𝑂(𝑉+𝐸), where 𝑉 is the number of vertices (cells in the matrix), and 𝐸 is the number of edges (connections between cells).
                            Given that there are 𝑟 × 𝑐 cells and each cell has at most 8 neighbors, the complexity can be simplified to:
                            𝑂(𝑉+𝐸)=𝑂(𝑟𝑐+8𝑟𝑐)=𝑂(𝑟𝑐)
        Space Complexity - O(r*c)
    */
}

int numberOfIslands(vector<vector<int>> arr , int r ,int c){
    int count = 0;
    vector<vector<int>> visited(r, vector<int>(c,false));
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(!visited[i][j] && arr[i][j]){
                count++;
                bfs(arr , visited , i , j , r, c);
            }
        }
    }
    return count;
    /*
        Time Complexity - O(r*c) - visiting every element
        Space Complexity - O(r*c) - visited array size
    */
}

int main(){
    int r , c;
    cin>>r>>c;
    vector<vector<int>> arr(r , vector<int>(c));

    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin>>arr[i][j];
        }
    }

    cout<<numberOfIslands(arr , r, c);
}
/*
    Test case : 
    5 4
    0 1 1 0
    0 1 1 0
    0 0 1 0
    0 0 0 0
    1 1 0 1
    
    Output:
    3
*/