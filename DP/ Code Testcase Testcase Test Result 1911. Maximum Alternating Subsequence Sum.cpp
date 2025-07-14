#include <vector>
using namespace std;

class Solution {
public:
    typedef long long ll;
    int n ;
    long long solve(int idx , vector<int>&nums , bool flag){

        if(idx >= n) return 0;
        
        ll val = nums[idx];
        if(flag == false) val = -val;

        ll skip = solve(idx+1 , nums, flag);
        ll take = solve(idx +1 , nums , !flag) + val;        

        return max(skip , take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
         n = nums.size();
        return solve(0 , nums , true);
        
    }
};

//mem solution
class Solution {
public:
    long long dp[100001][2] ;
    typedef long long ll;
    int n ;

    Solution(){ // init 2d like this okay .. this is cpp syntax 
        for(int i =0  ; i< 100001 ; i++){
            dp[i][0] = dp[i][1] = -1;
        }
    }
    long long solve(int idx , vector<int>&nums , bool flag){

        if(idx >= n) return 0;
        
        if(dp[idx][flag] != -1) return dp[idx][flag];

        ll val = nums[idx];
        if(flag == false) val = -val;

        ll skip = solve(idx+1 , nums, flag);
        ll take = solve(idx +1 , nums , !flag) + val;        

        return   dp[idx][flag]= max(skip , take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
         n = nums.size();
        return solve(0 , nums , true);
        
    }
};

