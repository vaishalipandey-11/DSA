#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int m;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& grid, queue<pair<int, int>>& q, int i,
             int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1)
            return;

        grid[i][j] = 2;
        q.push({i, j});

        for (auto& dir : dirs) {
            dfs(grid, q, i + dir[0], j + dir[1]);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        bool found = false;

        queue<pair<int, int>> q;

        // 1st island  mark
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < m && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, q, i, j);
                    found = true;
                }
            }
        }

        int steps = 0;
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto& dir : dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        if (grid[nx][ny] == 1) {
                            return steps; // mil gaya island
                        }
                        if (grid[nx][ny] == 0) {
                            grid[nx][ny]=2;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};