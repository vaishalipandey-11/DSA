#include <vector>
using namespace std;
class Solution {
public:
    int N, M;
    int solve(int i, int j) {
        if (i < 0 || j < 0 || i >= M || j >= N)
            return 0;
        if (i == M - 1 && j == N - 1)
            return 0;
        int right = solve(i + 1, j);
        int down = solve(i, j + 1);
        return right + down;
    }
    int uniquePaths(int m, int n) {
        N = n;
        M = m;
        return solve(0, 0);
    }
};
//this is mem solution 
class Solution {
public:
    int N, M;

    int solve(int i, int j, vector<vector<int>>&dp) {
        if (i < 0 || j < 0 || i >= M || j >= N)
            return 0;
        if (i == M - 1 && j == N - 1)
            return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int right = solve(i, j + 1, dp);
        int down = solve(i + 1, j , dp);
        return dp[i][j]= right + down;
    }
    int uniquePaths(int m, int n) {
        N = n;
        M = m;
       vector<vector<int>>dp(m+1, vector<int>(n+1 , -1));
        return solve(0, 0 , dp);
    }
};

//bottomup approach
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n));
        dp[0][0]  =1 ; //as  per the tc robo 
        //lets fill oth row and col with 1 
        for(int col = 1 ; col<n ; col++){//fill row
            dp[0][col]=1;
        }
        //fill col
        for(int row =1 ; row<m ; row++){
            dp[row][0]=1;
        }
      
         for(int i=1 ; i<m ; i++){
            for(int j =1 ; j<n ; j++){
                dp[i][j]= dp[i-1][j] + dp[i][j-1];
            }
         }
         return dp[m-1][n-1];
        
    }
};