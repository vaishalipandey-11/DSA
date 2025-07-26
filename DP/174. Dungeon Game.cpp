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