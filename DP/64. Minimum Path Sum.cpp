#include <vector>
using namespace std;
#include <climits>
#include <cstring>
class Solution {
public:
    int m, n;
    int minsum = INT_MAX;
    int solve(int i, int j, int sum ,vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= m || j >= n){
            return 0;
        }else{
            sum +=grid[i][j];
        }
        if (i == m - 1 && j == n - 1) {
            minsum = min(minsum, sum);
        }
        int right = solve(i , j+1 , sum , grid );
        int down = solve(i+1 , j , sum , grid);

        return minsum;
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
         return solve(0,0,0,grid);
    }
};

// Optimized version using memoization
//tc: O(m*n)
//sc: O(m*n) + O(m+n) for recursion stack
class Solution {
public:
    int m, n;
    int dp[201][201];

    int solve(int i, int j, vector<vector<int>>& grid) {
        if (i >= m || j >= n)
            return INT_MAX;

        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve(i, j + 1, grid);
        int down = solve(i + 1, j, grid);

        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, grid);
    }
};

//this is the tabulation approach
//tc: O(m*n)
//sc: O(m*n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        dp[0][0] = grid[0][0];

        // fill row first
        for (int col = 1; col < n; col++) {
            dp[0][col] = grid[0][col] + dp[0][col - 1];
        }
        // fill for col
        for (int row = 1; row < m; row++) {
            dp[row][0] = grid[row][0] + dp[row - 1][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[m - 1][n - 1];
    }
};