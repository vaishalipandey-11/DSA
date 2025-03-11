/// here we have a to switching start and i ...
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include<vector>
class Solution {
public: 
    int n ;
    void solve(int idx , vector<int> & nums , vector<vector<int>>&result){
        if(idx == n ){
            result.push_back(nums);
            return;
        }
        for(int i = idx ; i<n ;i++){
            swap(nums[idx], nums[i]);
            solve(idx+1 , nums ,result);
            swap(nums[idx],  nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>result ;
        solve(0 , nums, result);
        return result;
    }
};



class Solution {
public:
    int n;
    unordered_set<int>st;
    void solve(vector<int>temp , vector<int>&nums , vector<vector<int>>&result){
        if(temp.size() == n){
            result.push_back(temp);
            return ;
        }
        for(int i =0 ; i<n ; i++){
            if(st.find(nums[i]) == st.end()){
                 temp.push_back(nums[i]);
                 st.insert(nums[i]);
                 solve(temp , nums , result);
                   temp.pop_back();
                   st.erase(nums[i]);
            }
           
            
        }
        
    }

    vector<vector<int>> permute(vector<int>& nums) {

        n = nums.size();
        vector<vector<int>> result ;
        vector<int>temp ;
         solve(temp , nums, result);
         return result ;
    }
};