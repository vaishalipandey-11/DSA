#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include<vector>
// method 1 with the use  of sets for unique permutation identifications 
class Solution {
public:
 void p_helper2(vector<vector<int>>&ans , vector<int>&nums , int start ){
    // bc 
    if( start == nums.size()){
        ans.push_back(nums);
        return;
    }
    // we can use unodered map for that 
        unordered_map<int,bool>visited;
    // 1 case m solve karungi 
     for(int i = start ; i<nums.size() ; i++){
        if(visited.find(nums[i]) != visited.end()){  // check for the value in visited 
            continue;
        } 
        visited[nums[i]]= true; // mark the swapped one as true 
        swap(nums[i] , nums[start]);
        p_helper2(ans , nums , start+1);
        swap(nums[i], nums[start]);
     }
   }
   void p_helper(vector<vector<int>>&ans , vector<int>&nums , int start ){
    // bc 
    if( start == nums.size()){
        ans.push_back(nums);
        return;
    }
    // 1 case m solve karungi 
     for(int i = start ; i<nums.size() ; i++){
        swap(nums[i] , nums[start]);
        p_helper(ans , nums , start+1);
        swap(nums[i], nums[start]);
     }
   }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        p_helper(ans , nums , 0);
        set<vector<int>>st;
        for(auto e:ans){
            st.insert(e);
        }
        ans.clear();
        for(auto e:st){
            ans.push_back(e);
        }
        return ans ;
    }
};