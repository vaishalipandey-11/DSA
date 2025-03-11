#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include<vector>
class Solution {
public:
// 2 pointer approach 
    vector<int> twoSum(vector<int>& nums, int target) {
    
        // sort nums on the bases of nums  
       vector<pair<int,int>>SortedNums; // value and i
       for(int i =0; i<nums.size() ;i++){
             SortedNums.push_back({nums[i],i});
       }
       // sort
       sort(SortedNums.begin(), SortedNums.end());
       // now use to pointer to get the sum 
       int left = 0 ; int  right = nums.size()-1;

    while (left < right) {
        int sum = SortedNums[left].first + SortedNums[right].first;

        if (sum == target) 
            return {SortedNums[left].second, SortedNums[right].second};
        else if (sum < target) 
            left++;  
        else  
            right--;  
    }

    return {};

    }
};

// brute force approach

class Solution {
public:  
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                if((nums[i]+nums[j])==target){
                ans.push_back(i);
                    ans.push_back(j);
                }
            }
            
        }
        return ans;
    }
};