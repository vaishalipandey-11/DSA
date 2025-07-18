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