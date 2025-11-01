#include <bits/stdc++.h>
using namespace std;    

class Solution {
public:
    int canwesplit(vector<int>& nums, int mid) {
        int sub = 1;
        int curr = 0;

        for (auto& it : nums) {
            if (curr + it > mid) {
                sub++;
                curr = it;

            } else {
                curr += it;
            }
        }
        return sub;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
       

        while (l < r) {
            int mid = (l + r) / 2;
            if (canwesplit(nums, mid) <= k)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};