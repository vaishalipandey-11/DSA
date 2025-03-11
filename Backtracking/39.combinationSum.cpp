#include <iostream>
using namespace std;
#include<vector>

class Solution {
public:
     void combinationSum_helper(vector<int>& candidates, int target , vector<int>&v ,vector<vector<int>>&ans, int  index ) {

     // base case
        if(target == 0){
            ans.push_back(v);
            return ;
        }
         if(target < 0){
             return ;
         }
     //1 case m solve krungi 
     // i as index taki necxt time bhi same value pe hi try kare 
     for(int i = index ; i <candidates.size() ; i++){
        v.push_back(candidates[i]);
        combinationSum_helper(candidates, target-candidates[i] , v , ans,i );
        v.pop_back();

     }  
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        vector<vector<int>>ans;
        combinationSum_helper(candidates , target ,v, ans,0);
        return ans ;
        
    }
};