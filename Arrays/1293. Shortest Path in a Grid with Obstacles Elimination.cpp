#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        queue<vector<int>> q;// q for bfs
        bool vis[41][41][1601]; //to track visited 
        memset(vis, false, sizeof(vis));// fill vis

        // i,j,k
        vector<vector<int>> dir = { {-1, 0}, {1, 0}, {0, 1},{0,-1} }; // in the dir of --->bfs
        q.push({0, 0, k}); // push 1st
        vis[0][0][k]=true; //mark vis

        int steps = 0;   // track count 
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                vector<int> temp = q.front();
                q.pop();
                int curr_i = temp[0];
                int curr_j = temp[1];
                int obs = temp[2];

                if (curr_i == n - 1 && curr_j == m - 1) // AGR last pe h toh return count please
                    return steps;

                for (auto& d : dir) { // new dir
                    int new_i = curr_i + d[0];
                    int new_j = curr_j + d[1];

                    if (new_i < 0 || new_i >= n || new_j < 0 ||
                        new_j >=m) { //out of  bound case
                        continue;
                    } 

                   int  new_obs =obs- grid[new_i][new_j];
                    if(new_obs >=0 && !vis[new_i][new_j][new_obs]){
                        q.push({new_i , new_j , new_obs});
                        vis[new_i][new_j][new_obs] = true;
                    }
                }
            }
            steps++;

        }
        return -1;
    }
};