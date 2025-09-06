
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    int n;
    int m;

    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int dfs(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 0;
        int area = 1;
        for (auto& it : dir) {
            int new_i = it[0] + i;
            int new_j = it[1] + j;

            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m &&
                grid[new_i][new_j] == 1) {
                area += dfs(new_i, new_j, grid);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int max_ans = 0;

        int curr = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    curr = dfs(i, j, grid);
                }
                max_ans = max(curr, max_ans);
            }
        }
        return max_ans;
    }
};