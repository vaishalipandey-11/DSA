#include <vector>
#include <string>
#include <cstring>
//tc: O(n^2)
//sc: O(n^2)
using namespace std;
class Solution {
public:

// rec + mem solution 
    int dp[1001][1001];
    int lps(string & s, int i, int j) {
        if (i > j)
            return 0;
        if (i == j)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == s[j])
            return dp[i][j]= 2 + lps(s, i + 1, j - 1);
        else
            return dp[i][j]= max(lps(s, i,j-1), lps(s,i+1 , j));
    }
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        return lps(s, 0, n - 1);
    }
};

class Solution {
public:
// this is bottom up approach 
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int i = 0 ; i<n ; i++){
            dp[i][i]=1; // size is 1 so 1 ;
        }
        //for 2 length
        for(int L =2 ; L<=n ; L++){
            for(int i =0 ; i<n-L+1  ; i++){
                int j = i+L-1;
                if(s[i]==s[j]) dp[i][j] = 2+dp[i+1][j-1];
                else dp[i][j]= max(dp[i][j-1],dp[i+1][j]);
            }
        }
        return dp[0][n-1];
        
    }
};