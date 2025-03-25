#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include<vector>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
          int maxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i; j < nums.size(); j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }
                 maxi = max(maxi, sum);
        }
    }
      return maxi;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
          int maxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i; j < nums.size(); j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }
                 maxi = max(maxi, sum);
        }
    }
      return maxi;
    }
};
// best approach for solving  this problem 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxval = INT_MIN;
        int sum =0;
        int n = nums.size();
        for(int i =0 ; i<n ; i++){
            sum += nums[i];
            if(sum > maxval) maxval = sum ;
            if(sum < 0 ) sum = 0 ;
        }
         return maxval ;
        
    }
};