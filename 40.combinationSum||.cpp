#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include<vector>

class Solution {
public:
    void combinationSum2_helper(vector<int>& candidates, int target, vector<int>&v , vector<vector<int>>&ans , int index) {
    if(target ==0 ){
         ans.push_back(v);
         return ;
    }
    if(target <0 ){
         return ;
    }
        for(int i = index ; i<candidates.size() ; i++){
            // check prev and next index for taking combination
            if(i>index && candidates[i]== candidates[i-1]){
                continue;
            }
            // think condition 
            if(candidates[i]>target) break;
            v.push_back(candidates[i]);
            combinationSum2_helper(candidates ,target-candidates[i] , v , ans , i+1 );
            v.pop_back();
        }

    }
      
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v;
        vector<vector<int>>ans;
        // better to sort 1st 
       sort(candidates.begin(), candidates.end());
        combinationSum2_helper(candidates , target , v , ans , 0);

             return ans ;
        
    }
};