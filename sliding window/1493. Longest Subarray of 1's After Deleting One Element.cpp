#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxl =0;
        int czero =0;
        int i=0;
        int j =0;
        while(j<n){
            // condition if i 0
            czero += (nums[j]==0);

            // shirk the window please if count is greater than expected 
            while(czero > 1){
                czero -= (nums[i]==0);
                i++;
            }
           // count the max size of window 
            maxl = max(maxl , j-i);
            j++; // dont forget to update j
        }
        return maxl;
    }
};