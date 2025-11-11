#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int max_ele(vector<vector<int>>& mat, int col) {
        int n = mat.size();
        int index = INT_MAX;
        int curr_max = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (mat[i][col] > curr_max) {
                index = i;
                curr_max = mat[i][col];
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0;
        int h = m - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            int row = max_ele(mat, mid);

            int left = mid - 1 >= 0 ? mat[row][mid - 1] : INT_MIN;
            int right = mid + 1 <= m - 1 ? mat[row][mid + 1] : INT_MIN;

            if (left < mat[row][mid] && mat[row][mid] > right) {
                return {row, mid};
            } else if (left < mat[row][mid]) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return {-1, -1};
    }
};