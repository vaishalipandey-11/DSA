
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int result = INT_MAX;

        int i =0 , j =0;
        int sum =0;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                result = min(result,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return result == INT_MAX ? 0 : result; 
        
    }
};