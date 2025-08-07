#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        for(int i=n-3 ; i>=0 ; i--){ // loop from end to get the map parameter 
            if((nums[i] +nums[i+1])>nums[i+2]){
                return nums[i]+nums[i+1]+nums[i+2];
            }
        }
        return 0;
        
    }
};