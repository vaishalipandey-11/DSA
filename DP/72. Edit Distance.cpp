#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n , m;
    int solve(string word1, string word2 , int i , int j){
        if(i==m){
            return n-j;// insert all
        }else if(j==n){
            return m-i;//delete
        }

        if(word1[i]==word2[j]){
          return   solve(word1, word2 ,i+1 , j+1);
        }else{
            int insertc = 1+ solve(word1 , word2 ,i , j+1);
            int deletec = 1+ solve(word1 ,word2, i+1 , j);
            int replacec = 1+ solve(word1 , word2 ,i+1 , j+1 );
            return min(insertc , min(deletec , replacec));
        }
        return -1;
        
    }
    int minDistance(string word1, string word2) {
         m= word1.size();
         n = word2.size();
        return solve(word1, word2 , 0,0);
        
    }
};
//this is memoization
// Approach-2 (Using Memoization)
// T.C : O(m*n)
// S.C : O(m*n) + O(m+n) for recursion stack space
#include <bits/stdc++.h>
class Solution {
public:
    int n , m;
    int dp[501][501];
    int solve(string &word1, string &word2 , int i , int j){
        if(i==m){
            return n-j;// insert all
        }else if(j==n){
            return m-i;//delete
        }
        if(dp[i][j] != -1 ) return dp[i][j];

        if(word1[i]==word2[j]){
          return   solve(word1, word2 ,i+1 , j+1);
        }else{
            int insertc = 1+ solve(word1 , word2 ,i , j+1);
            int deletec = 1+ solve(word1 ,word2, i+1 , j);
            int replacec = 1+ solve(word1 , word2 ,i+1 , j+1 );
            return dp[i][j] = min(insertc , min(deletec , replacec));
        }
        return -1;
        
    }
    int minDistance(string word1, string word2) {
         m= word1.size();
         n = word2.size();
         memset(dp , -1 , sizeof(dp));
        return solve(word1, word2 , 0,0);
        
    }
};
//this is starting from m and n 

class Solution {
public:
    int n , m;
    int dp[501][501];
    int solve(string &word1, string &word2 , int m , int n){
        if(m==0 || n ==0) return m+n;
        if(dp[m][n] != -1 ) return dp[m][n];

        if(word1[m-1]==word2[n-1]){
          return   solve(word1, word2 ,m-1, n-1);
        }else{
            int insertc = 1+ solve(word1 , word2 ,m , n-1);
            int deletec = 1+ solve(word1 ,word2, m-1 , n);
            int replacec = 1+ solve(word1 , word2 ,m-1 , n-1 );
            return dp[m][n] = min(insertc , min(deletec , replacec));
        }
        return -1;
        
    }
    int minDistance(string word1, string word2) {
         m= word1.size();
         n = word2.size();
         memset(dp , -1 , sizeof(dp));
        return solve(word1, word2 , m,n);
        
    }
};

//this is bottom up approach
//tc : O(m*n)
//sc : O(m*n)   
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

            for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = i + j;
                else if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = 1+
                        min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
                }
            }
        }
        return dp[m][n];
    }
};