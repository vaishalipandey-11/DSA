#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;
        int ans = INT_MAX;

        while (l <= h) {

            int mid = l + (h - l) / 2;

            if(nums[l] <= nums[mid]){
                ans = min(ans, nums[l]);
                l=mid+1;
            }else{
                h=mid;

            }
        }
        return ans;
    }
};