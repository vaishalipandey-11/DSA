#include<vector>
using namespace std;

class Solution {
public:
int n , m;
    int solve(int  i , int j ,vector<vector<int>>& obstacleGrid ){
        if(i<0 || j<0 || i>=m || j>=n || obstacleGrid[i][j] ==1) return 0;

        if(i == m-1 && j == n-1) return 1;
        int right = solve(i, j+1,obstacleGrid );
        int down = solve(i+1 , j, obstacleGrid);
        return right +down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
      return solve(0,0,obstacleGrid);
    }
};

class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& obstacleGrid) {
        if (i < 0 || j < 0 || i >= m || j >= n || obstacleGrid[i][j] == 1)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        int right = solve(i, j + 1, obstacleGrid);
        int down = solve(i + 1, j, obstacleGrid);
        return dp[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, -1));

        return solve(0, 0, obstacleGrid);
    }
};