#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int totalsum =( n*(n+1))/2;
        int sum =0;
     for(int i =0 ; i<n ; i++){
         sum += nums[i];
     }
     return totalsum-sum;
    }
};