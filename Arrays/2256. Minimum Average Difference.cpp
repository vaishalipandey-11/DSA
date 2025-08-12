
#include<iostream>
#include<bits/stdc++.h>
using namespace std;    
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long miniavg = INT_MAX;
       long long totalsum = 0;
        for (int i = 0; i < n; i++) {
            totalsum += nums[i];
        }

        long long currsum =0;
        int idx=-1;
        for (int i = 0; i < n; i++) {
               currsum += nums[i];
                long long leftAvg = currsum / (i + 1);
                long long rightAvg = (i == n - 1) ? 0 : (totalsum - currsum) / (n - i - 1); // fixed denominator + last index case
                int diff = (int)abs(leftAvg - rightAvg);
            if(diff<miniavg){
                miniavg = diff;
                idx =i;
            }

        }
        return idx;
    }
};