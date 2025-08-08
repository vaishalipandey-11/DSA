#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> fill(n + 1, 0);
        vector<int> res(2, 0);
        for (int i = 0; i < n; i++) {
            if (fill[nums[i]] == 0) {
                fill[nums[i]] = -1;
            } else {
                res[0] = nums[i];
            }
        }
        for (int i = 1; i <= n; i++) {
            if (fill[i] == 0) {
                res[1] = i;
                break;
            }
        }
        return res;
    }
};