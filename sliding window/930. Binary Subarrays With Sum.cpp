#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
public:
    //Approach-1 (Simple prefix sum) - These kind of Qns can always be solved using Map and cumulative sum technique
    //T.C : O(n)
    //S.C : O(n)
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        
        int count   = 0;
        int currSum = 0;
        mp[0] = 1;
        for(int &num : nums) {
            
            currSum += num;

            if(mp.find(currSum - goal) != mp.end()) {
                count += mp[currSum - goal];
            }
            
            mp[currSum]++;
            
            
        }
        
        return count;
    }
};