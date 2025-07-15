#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int n ;
    int solve(vector<int>&nums , int i , int p){
        n= nums.size();
        if(i>=n) return 0;
        int take =0 ; // count of take means max increasing 
        if(p == -1 || nums[p]<nums[i]){// means next one is in increasing sequence 
        take = 1+solve(nums , i+1 , i); // make sure you update p after taking 

        }
        int skip = solve(nums , i+1 , p); // p remains same bcz we skipped the i 

        return max(skip , take);
    }
    int lengthOfLIS(vector<int>& nums) {

       return solve(nums,0,-1);
    }
};

class Solution {
public:
    int n ;
    // 2 var are changing so we need a 2D dp okay
    int dp[2501][2501];
    int solve(vector<int>&nums , int i , int p){
        n= nums.size();
        if(i>=n) return 0;

        if(p != -1 && dp[i][p] != -1) return dp[i][p];

        int take =0 ; // count of take means max increasing 

        if(p == -1 || nums[p]<nums[i]){// means next one is in increasing sequence 
        take = 1+solve(nums , i+1 , i); // make sure you update p after taking 

        }
        int skip = solve(nums , i+1 , p); // p remains same bcz we skipped the i 

        if(p != -1){
            dp[i][p] = max(skip , take);
        }
        return max(skip , take);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1 , sizeof(dp));

       return solve(nums,0,-1);
    }
};