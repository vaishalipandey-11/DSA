
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    void solve(vector<int>&nums , int idx , vector<int>&curr , vector<vector<int>>&result){
        if(idx == nums.size()){
            result.push_back(curr);
            return ;
        }

        curr.push_back(nums[idx]);// do 
        solve(nums , idx+1 , curr ,result ); // explore 

        curr.pop_back(); // undo 
        solve(nums, idx+1 , curr , result);

        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<int > curr ;
         
         vector<vector<int>>result;
         solve(nums , 0 ,curr ,result );
         return result ;
    }
};