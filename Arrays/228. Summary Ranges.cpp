#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if(n == 0) return ans;
        
        int i = 0;
        while(i < n) {
            int start = nums[i];
            int end = nums[i];
            
            // extend while consecutive
            while(i + 1 < n && nums[i+1] == nums[i] + 1) {
                i++;
                end = nums[i];
            }
            
            if(start == end) {
                ans.push_back(to_string(start));
            } else {
                ans.push_back(to_string(start) + "->" + to_string(end));
            }
            i++;
        }
        
        return ans;
    }
};
