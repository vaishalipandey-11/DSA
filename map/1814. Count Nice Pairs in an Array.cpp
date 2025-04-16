#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
public:
    int M = 1e9 + 7;
    // reverse ftn 
    int reverse(int num) {
    int ans = 0;
    while (num > 0) {
        ans = ans * 10 + num % 10;
        num /= 10;
    }
    return ans;
}

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i =0 ; i<n ; i++){
            nums[i] = nums[i]-reverse(nums[i]);
        }


        int paircount =0;
        for(int i=0 ; i<n ; i++){
          paircount = ( paircount+ mp[nums[i]]) % M;//peece kitni baar aya h 
          mp[nums[i]]++; // update the count 
        }

        return  paircount ;
    }
};