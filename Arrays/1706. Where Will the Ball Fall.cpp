#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>res;

        for (int i = 0; i < m; i++) {
            int row = 0;
            int col = i;
            bool atka = false;

            while (row < n ) {
                if (grid[row][col] == 1) { // aise case jaha vo atk skta h ..
                                           // col end pe y next -1 ho
                    if (col == m-1|| grid[row][col + 1] == -1) {
                        atka = true;
                        break;
                    } 
                    col++;
                    row++;
                    

                } else { // ==-1 toh row 0 ho y left wala 1 ho
                    if (col == 0 || grid[row][col - 1] == 1) {
                        atka = true;
                        break;
                    }
                    col--;
                    row++;
                }
            }
            res.push_back(atka ? -1 : col);
        }
        return res;
    }
};