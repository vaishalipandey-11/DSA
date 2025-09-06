
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        
       
         int good_count =0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]==1){
                    good_count++;
                }
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = 2;
                }
            }
        }

        int min = -1;
        while (!q.empty()) {
            int s = q.size();

            while (s--) {
                auto [a, b] = q.front();
                q.pop();

                for (auto& it : dir) {
                    int new_a = it[0] + a;
                    int new_b = it[1] + b;

                    if (new_a>=0 && new_a < n && new_b >=0 && new_b < m && grid[new_a][new_b] ==1) {
                        
                        if (grid[new_a][new_b] != 2) {
                            q.push({new_a, new_b});
                            grid[new_a][new_b] = 2;
                            good_count --;
                        }
                    }

                }
            }
            min++;
        }
        if(good_count >0) return -1;
        
        return  min ==-1 ? 0 : min ;
    }
};