#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSubarr = INT_MIN;
        int sum  =0 ;
           //Kadane's Algo for findig max subarray sum
        for(int i=0 ; i<n ; i++){
            sum+=nums[i];
            if(sum > maxSubarr) maxSubarr = sum;
            if(sum < 0) sum =0;
        }
         //Kadane's Algo for findig min subarray sum
        int minSubarr = INT_MAX;
         sum  =0 ;
        for(int i=0 ; i<n ; i++){
            sum+=nums[i];
            if(sum < minSubarr) minSubarr = sum;
            if(sum > 0) sum =0;
        }
        
    
         return max(abs(minSubarr) , maxSubarr);

    }
};


//Approach-2 (1 Pass - Kadane's Algorithm for maxsubarrysum and minsybarraysum inside one for loop)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int maxSum = nums[0];
        int minSum = nums[0];

        int currSumMax = nums[0];
        int currSumMin = nums[0];

        for(int i = 1; i < n; i++) {
            currSumMax = max(nums[i], currSumMax + nums[i]);
            maxSum = max(maxSum, currSumMax);


            currSumMin = min(nums[i], currSumMin + nums[i]);
            minSum     = min(minSum, currSumMin);
        }

        return max(maxSum, abs(minSum));


    }
};