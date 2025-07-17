//solution without memoization
//tc: O(2^n) , sc: O(n)
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int n, m;
    int solve(string&s1, string&s2 , int i , int j ){
        if(i>=n || j>=m) return 0 ;// out of bound conditon or edge case 
        if(s1[i]==s2[j]) return 1+ solve(s1,s2,i+1 , j+1 );
        return max(solve(s1,s2,i+1 , j) , solve(s1,s2,i, j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();
        return solve(text1, text2, 0, 0);
    }
};
//with memoization
//tc: O(n * m) , sc: O(n * m)
#include <cstring>
class Solution {
public:
    int dp[1001][1001];
    int n, m;
    int solve(string& s1, string& s2, int i, int j) {
        if (i >= n || j >= m)
            return 0; // out of bound conditon or edge case
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j])
            return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        return dp[i][j] = max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();
        memset(dp,-1,sizeof(dp));
        return solve(text1, text2, 0, 0);
    }
};