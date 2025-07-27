#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int m ,n ;
 int solve(int i , int j , vector<vector<int>>&dungeon){
    //bc--out of bound ka
    if(i>=m || j>=n) return INT_MAX;
    //princess k pass 
    if(i==m-1 && j ==n-1){
        if(dungeon[i][j]>0) return 1;
        return abs(dungeon[i][j])+1; 
    } 
    int right = solve(i , j+1 , dungeon);
    int down = solve(i+1 , j , dungeon);
    // at the top the mini value needed
    int result = min(right , down) - dungeon[i][j];

    return max(1, result);

 }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
       return solve(0,0,dungeon);
        
    }
};

//tc O(m*n) and sc O(m*n) for dp array
//sc O(m+n) for recursion stack
class Solution {
public:
int m ,n ;
int dp[201][201];

 int solve(int i , int j , vector<vector<int>>&dungeon){
    //bc--out of bound ka
    if(i>=m || j>=n) return INT_MAX;

    if(dp[i][j] != -1) return dp[i][j];
    //princess k pass 
    if(i==m-1 && j ==n-1){
        if(dungeon[i][j]>0) return 1;
        return abs(dungeon[i][j])+1; 
    } 
    int right = solve(i , j+1 , dungeon);
    int down = solve(i+1 , j , dungeon);
    // at the top the mini value needed
    int result = min(right , down) - dungeon[i][j];

    return dp[i][j] = max(1, result);

 }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        memset(dp, -1 , sizeof(dp));
       return solve(0,0,dungeon);
        
    }
};

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=m-1 ; i>=0 ; i--){
            for(int j =n-1 ; j>=0 ; j--){
                if(i==m-1 && j ==n-1){
                    dp[i][j]=(dungeon[i][j]>0? 1 : abs(dungeon[i][j] )+1);
                }else{
                    int down = (i+1 >= m) ? 1e9 : dp[i+1 ][j];
                    int right = (j+1 >=n) ? 1e9 : dp[i][j+1];

                    int res = min(down , right ) -dungeon[i][j];

                    dp[i][j]= (res>0?res : 1);
                 }
            }
        }
        return dp[0][0];
    }
};