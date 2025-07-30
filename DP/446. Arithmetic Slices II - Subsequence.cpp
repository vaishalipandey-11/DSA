#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef long long ll;
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        vector<unordered_map<ll, int>> mp(n);// a vector of map

        for (int i = 0; i < n; i++) { // finding pairs 
            for (int j = 0; j < i; j++) {
                ll diff = (long)nums[i] -  (long) nums[j]; // get the diff please 

                int count_freq = mp[j].count(diff) ? mp[j][diff] : 0; // find the freq of that diff  with j

                result += count_freq; /// add freq to soln
                mp[i][diff] += count_freq + 1;  // update 
            }
        }
        return result;
    }
};