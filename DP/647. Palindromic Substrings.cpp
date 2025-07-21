//this is brute force solution
//time complexity is O(n^3)
//space complexity is O(1)
#include <string>
using namespace std;
class Solution {
public:
     bool solve(string &s ,int l , int r){
        while(l<=r){
            if(s[l] != s[r]) return false;
            else {
               l++;
               r--;
            }
        }
        return true;
     }
    int countSubstrings(string s) {
        int n = s.length();
        int count =0;
        for(int i =0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                if(solve(s,i,j)) count++;
            }
        }
        return count ;
        
    }
};
//recursive solution
//time complexity is O(n^3)
//space complexity is O(n)
class Solution {
public:
     bool solve(string &s ,int l , int r){
        while(l<=r){
            if(s[l] != s[r]) return false;
            else {
              return solve(s,l+1 , r-1);
            }
        }
        return true;
     }
    int countSubstrings(string s) {
        int n = s.length();
        int count =0;
        for(int i =0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                if(solve(s,i,j)) count++;
            }
        }
        return count ;
        
    }
};
//this is bottom-up dynamic programming solution
//time complexity is O(n^2)
//space complexity is O(n^2)
#include <bits/stdc++.h>
class Solution {
public:
    int dp[1001][1001];
    bool solve(string& s, int l, int r) {
        if (l >= r)
            return true;

        if (dp[l][r] != -1)
            return dp[l][r];

        if (s[l] == s[r])
            return dp[l][r] = solve(s, l + 1, r - 1);
        else
            return dp[l][r] = false;
    }

    int countSubstrings(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j))
                    count++;
            }
        }
        return count;
    }
};
//this is top-down dynamic programming solution
//time complexity is O(n^2)
//space complexity is O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;
        // for 1 length
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            count++;
        }
        // for 2 length
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                count++;
            }
        }
        // for more than 2
        for (int L = 3; L <= n; L++) {
            for (int i = 0; i <= n - L; i++) {
                int j = i + L - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};