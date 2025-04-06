
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//Approach-1 (Using simple backtracking to generate subsets)
//T.C : O(n * 2^n)
//S.C : O(n * 2^n)

class Solution {
public:

    void solve(vector<int>&nums , int i , vector<vector<int>>&Subsets , vector<int>&currSubset){
        int n = nums.size();
        if(i==n ) {
            Subsets.push_back(currSubset);
            return ;
        }

        currSubset.push_back(nums[i]);
        solve(nums, i+1 , Subsets , currSubset);
        currSubset.pop_back();
        solve(nums, i+1 , Subsets , currSubset);

    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> currSubset;
        vector<vector<int>>Subsets;
        solve(nums , 0 , Subsets , currSubset);
       int result =0;
        for(auto &currSubset : Subsets){
             int Xor =0;
            for(auto &m : currSubset){
                Xor ^=m;
            }
            result += Xor ;
        }
        return result ;
    }
};

//Approach-2 (Using optimal backtracking)
//T.C : O(2^n)
//S.C : O(n)
class Solution {
public:
     // optimal way where we are just calculating the xor or each subset not storing the whole subsets 
    int solve(vector<int>&nums , int i, int Xor ){
        int n = nums.size();
        if(i==n ) {
            return Xor ;
        }

      //  we have 2 choices either include or exclude 
       int I = solve(nums, i+1 , Xor^nums[i]);
     
       int E = solve(nums, i+1 ,Xor);
       
       return I + E;

    }
    int subsetXORSum(vector<int>& nums) {
        int Xor =0;
         return solve(nums , 0  , Xor);
       
    }
};


//Approach-3 (Observing pattern)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for(int &num : nums) {
            result |= num;
        }

        return result << (n-1);
    }
};