 // solving with same bfs? dfs / bfs+dfs approach 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int m;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0 ,-1}};
    void dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1)
            return;
        grid[i][j] = 2;
        for (auto& d : dir) {
            dfs(d[0] + i, d[1] + j, grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // mark all the boundry 1s
        for(int i =0; i<n ; i++){
            if(grid[i][0]==1) dfs(i , 0 , grid);
            if(grid[i][m-1]==1) dfs(i, m-1, grid);
        }
        for(int j=0 ; j<m ; j++){
            if(grid[0][j]==1) dfs(0,j, grid);
            if(grid[n-1][j]==1) dfs(n-1 , j , grid);
        }

        // now count the total 1 left 
        int count =0;
        for(int i=0 ; i<n; i++){
            for(int j =0 ; j<m ; j++){
                if(grid[i][j]==1) count ++;
            }
        }
        return count ;
    }
};