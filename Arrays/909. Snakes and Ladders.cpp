
#include<iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    pair<int, int> getpos(int s, int n) {
        int row = n - 1 - (s - 1) / n;
        int col = (s - 1) % n;
        if ((n - row) % 2 == 0) { // reverse direction on even row from bottom
            col = n - 1 - col;
        }
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<int> que;
        que.push(1);
        visited[1] = true;
        int steps = 0;

        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                int front = que.front();
                que.pop();
                if (front == n * n)
                    return steps;

                for (int dice = 1; dice <= 6 && front + dice <= n * n; dice++) {
                    int next = front + dice;
                    auto [row, col] = getpos(next, n);

                    if (board[row][col] != -1) {
                        next = board[row][col]; // snake or ladder
                    }

                    if (!visited[next]) {
                        visited[next] = true;
                        que.push(next);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
