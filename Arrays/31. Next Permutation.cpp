#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // find gola first
        int gola = -1;
        for (int i = n - 1; i > 0;
             i--) { // i-1 check krna h toh i>=0 nhi ho ksta h
            if (nums[i - 1] < nums[i]) {
                gola = i - 1;
                break;
            }
        }

        if (gola != -1) { // agr -1 nhi h tph find kro vrna sirf reverse kro
                          // sbko 145->541 this is next permutation
            // now find next great from gola
            for (int j = n - 1; j > gola; j--) {
                if (nums[j] > nums[gola]) {
                    swap(nums[j], nums[gola]);
                    break;
                }
            }
        }

        // now reverse the rest please
        reverse(nums.begin() + gola + 1, nums.end());
    }
};