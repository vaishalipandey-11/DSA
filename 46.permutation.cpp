/// here we have a to switching start and i ...
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include<vector>
class Solution {
public:
    void permuthelper(vector<int>&nums , vector<vector<int>>&ans , int start){
        // base case 
        if(start == nums.size()){
            ans.push_back(nums);
            return ;
        }
         // 1case m solve karungi
         for(int i = start ; i<nums.size() ;i++){
            swap(nums[i], nums[start]);
            permuthelper(nums , ans , start+1);
            // backtrack
            swap(nums[i] , nums[start]);
         }

            }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans ;
        permuthelper(nums , ans , 0);
        return ans;
        
    }
};