#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     vector<vector<int>>dir = {{-1,0}, {1,0},{0,1},{0,-1}};
     int n ; 
     int m;
      
      void dfs(int i ,int j , vector<vector<int>>&grid){ // 0 k alawa sbko 2 mark kr do
        if(i<0 || j<0 || i>=n || j >=m || grid[i][j] !=0) return ;
        grid[i][j] = 2;

        for(auto &d : dir){
            dfs(d[0]+i , d[1]+j , grid);
        }
        
      }

    int closedIsland(vector<vector<int>>& grid) {
         n = grid.size();
         m= grid[0].size();

        // sare bondary k 0 mark kr do 
        for(int i=0 ; i<n ;i++){
            if(grid[i][0]==0) dfs(i ,0 ,grid);
            if(grid[i][m-1]==0) dfs(i , m-1 , grid);
        }

        for(int j=0 ; j<m ; j++){
            if(grid[0][j]==0) dfs(0,j , grid);
            if(grid[n-1][j]==0) dfs(n-1 , j , grid);
        }

        // hr 0 pe ja kr dfs call kr do or mark ho jayenge 
        int count =0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]==0){
                    dfs(i , j , grid);
                    count ++;
                }
            }
        }
        return count ;
        
    }
};