
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    int n ;
    int m ;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(int i, int j, vector<vector<char>>& board) {
        board[i][j] = '.';

        for (auto& it : dir) {
            int new_i = i+it[0];
            int new_j = j+it[1];
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m &&
                board[new_i][new_j] == 'X') {
                dfs(new_i, new_j, board);
            }
        }
        
    }
    int countBattleships(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X') {
                    count ++;
                    dfs(i, j, board);
                }
            }
        }

        return count;
    }
};