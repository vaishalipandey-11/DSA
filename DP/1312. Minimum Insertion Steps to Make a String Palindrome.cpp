#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
// rec + mem solution
    int n;
    int dp[501][501];
    int solve(string &s, int i, int j) {
        if (i >=j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == s[j])
            return dp[i][j] = solve(s, i + 1, j - 1);
        else
            return dp[i][j] = 1 + min(solve(s, i + 1, j), solve(s, i, j - 1));
    }
    int minInsertions(string s) {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, n - 1);
    }
};

class Solution {
public:
  // this is bottom up (tabulation )
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n));
        // for length 1
        for (int i = 0; i < n; i++)
            dp[i][i] = 0;

        // for length 2
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;
                if (s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                dp[i][j] = 1+min(dp[i][j-1],dp[i+1][j]);    
            }
        }
        return dp[0][n-1];
    }
};